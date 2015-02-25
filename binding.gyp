{
  "targets": [
    { 
      'target_name': 'trace_hooks',
      'sources': [ 
          './src/trace_hooks.cc',
          './trace-hooks.js',
        ],
        'include_dirs': [
          '<!(node -e "require(\'nan\')")',
      ],
    }
  ]
}
