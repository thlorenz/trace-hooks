'use strict';

var binding = require('nad-bindings')('trace_hooks');

console.log('node version', process.version);
console.log('> JS: Hi from JS trace_hooks\n> C++:', binding.trace_hooks());
