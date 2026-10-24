; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $620F
.include "src/rom/event_command_macros.inc"
event_19F_command_620F:
    event_actor_walk 2, 0, 8
event_19F_command_6212:
    event_wait_idle 
