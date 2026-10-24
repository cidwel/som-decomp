; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $28BD
.include "src/rom/event_command_macros.inc"
event_106_command_28BD:
    event_actor_walk 4, 3, 8
event_106_command_28C0:
    event_wait_idle 
