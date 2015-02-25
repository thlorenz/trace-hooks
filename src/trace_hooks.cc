#include <nan.h>
#include "hooks.h"

using namespace v8;
 
static node::Hooks::FunctionEntryEventBuffer functionEntries;
static node::Hooks::JitCodeEventBuffer jitCodeEvents;

void OnFunctionEntry(uintptr_t function,
                     uintptr_t return_addr_location) {
  fprintf(stderr, "OnFunctionEntry\n");
}

void OnJitCodeEvent(const JitCodeEvent* event) {
  fprintf(stderr, "OnJitCodeEvent\n");
}

void print_events(node::Hooks::JitCodeEventBuffer events) {
  node::Hooks::JitCodeEventBuffer::const_iterator iter = events.begin();
  const v8::JitCodeEvent* ev;
  
  while(iter != events.end()) {
    ev = (*iter);
    /*if (ev->name.str != NULL) {
      fprintf(stderr, "%s", ev->name.str);
    }*/
    ++iter;
  }
}

NAN_METHOD(Trace_hooks) {
  NanScope();

  NanReturnValue(NanNew("trace_hooks says hello"));
}

void init_trace_hooks(v8::Handle<v8::Object> exports) {
  node::Hooks::FunctionEntryEventBuffer collectedEntries;
  collectedEntries = node::Hooks::registerFunctionEntryHook(OnFunctionEntry);

  node::Hooks::JitCodeEventBuffer collectedEvents;
  collectedEvents = node::Hooks::registerJitCodeEventHook(OnJitCodeEvent);
  print_events(collectedEvents);

  NODE_SET_METHOD(exports, "trace_hooks", Trace_hooks);
}

NODE_MODULE(trace_hooks, init_trace_hooks)
