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
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7',
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      },
      'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
    }
  ]
}
