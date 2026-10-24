; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AA9B
.include "src/rom/event_command_macros.inc"
event_28B_command_AA9B:
    event_actor_walk 4, 1, 32
event_28B_command_AA9E:
    event_wait_idle 
event_28B_command_AA9F:
    event_actor_walk 4, 3, 63
