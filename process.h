#include <stdint.h>
#include <stdio.h>

enum state {
  READY=0,
  RUNNING
};

struct process {
  uint32_t p_id;
  enum state p_state;
};

void p_switch_state(struct process *p);
void p_print(struct process *p);

void p_switch_state(struct process *p) {
  if (p->p_state == READY) {
    p->p_state = RUNNING;
  } else {
    p->p_state = READY;
  }
}

const char* convertToString(enum state name) {
  switch(name) {
    case READY: return "Ready";
    case RUNNING: return "Running";
  }
}

void p_print(struct process *p) {
  printf("Prozess mit der ID: %u\n und dem Status: %s", p->p_id, convertToString(p->p_state));
}
