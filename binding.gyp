{
  "targets": [
    {
      "target_name": "winregrestart",
      "conditions": [
        ['OS=="win"', {      
          "sources": [
            "src/winregrestart.cc"
          ]
        }]
      ]
    }
  ]
}
