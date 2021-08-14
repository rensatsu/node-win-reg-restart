# Register Application Restart

A Node.js module that adds methods for invoking the WinAPI
[`RegisterApplicationRestart`][reg-restart] and
[`UnregisterApplicationRestart`][unreg-restart] methods.

Due to limitations of these API methods, module may be incompatible
with some electron apps.

## Usage

Install module using npm:
```bash
npm i --save @rensatsu/win-reg-restart
```

Register an application to be restarted on Windows restart:
```javascript
const winRegRestart = require("@rensatsu/win-reg-restart");
const result = winRegRestart.registerApplicationRestart("--minimized");
console.log({ result });
```

## Original code

Original project: `node-windows-register-restart` by `kdelorey`.

This is a modified fork of the repository located [here][repo-original] licensed
under [MIT License][license-original].

<!-- Links -->

[reg-restart]: https://docs.microsoft.com/en-us/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart
[unreg-restart]: https://docs.microsoft.com/en-us/windows/desktop/api/winbase/nf-winbase-unregisterapplicationrestart
[repo-original]: https://github.com/kdelorey/node-windows-register-restart
[license-original]: https://github.com/kdelorey/node-windows-register-restart/blob/f333b651503a9f8f4731870697fe8db4b0f3020f/LICENSE
