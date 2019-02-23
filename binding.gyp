{
  "targets": [
    {
      "target_name": "windowsrestart",
      "conditions": [
        ['OS=="win"', {      
          "sources": [
            "src/winapprestart.cc"
          ]
        }]
      ]
    }
  ]
}