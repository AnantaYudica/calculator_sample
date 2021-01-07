{
  'targets': [
    {
      'target_name': 'calculator',
      'type': 'static_library',
      'include_dirs': ['../include'],
      'sources': ['../src/Calculator.cpp'],
      'cflags': ['-std=c++11']
    },
    {
      'target_name': 'hello',
      'sources': [
        'src/hello.cc'
      ]
    },
    {
      'target_name': 'calculator-intf',
      'sources': [
        'src/Calculator.intf.cc'
      ],
      'include_dirs': [
        "<!(node -p \"require('node-addon-api').include_dir\")",
        '../include',
        'include'
      ],
      'dependencies': ['calculator'],
      'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
    }
  ]
}
