#include <node.h>

#include <windows.h>
#include <iostream>
#include <string>

namespace windowsrestart {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Context;
using v8::Local;
using v8::MaybeLocal;
using v8::Maybe;
using v8::Object;
using v8::Value;
using v8::Boolean;
using v8::Number;
using v8::String;

void RegisterRestart(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    MaybeLocal<String> commandLineParam = args[0]->ToString(context);

    Maybe<int32_t> flagsParam = args[1].As<Number>()->Int32Value(context);

    std::wstring commandLineArgsConverter;
    const wchar_t* commandLineArgs = nullptr;
    int32_t noRestartFlags = 0;

    if (!commandLineParam.IsEmpty()) {
        String::Value t(isolate, commandLineParam.ToLocalChecked());
        
        //  The Win32 RegisterApplicationRestart can only take a WCHAR*.
        commandLineArgsConverter = std::wstring(*t, *t + t.length());
        commandLineArgs = commandLineArgsConverter.c_str();
    }

    if (!flagsParam.IsNothing()) {
        noRestartFlags = flagsParam.FromJust();
    }

    bool ok = ::RegisterApplicationRestart(commandLineArgs, noRestartFlags) == S_OK;

    args.GetReturnValue().Set(ok);
}


void UnregisterRestart(const FunctionCallbackInfo<Value>& args) {
  bool ok = ::UnregisterApplicationRestart() == S_OK;

  args.GetReturnValue().Set(ok);
}


void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "registerRestart", RegisterRestart);
  NODE_SET_METHOD(exports, "unregisterRestart", UnregisterRestart);
}

NODE_MODULE(registerrestart, init)

} // namespace windowsrestart