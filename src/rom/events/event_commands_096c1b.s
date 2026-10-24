; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C1B
.include "src/rom/event_command_macros.inc"
event_1B9_command_6C1B:
    event_actor_walk 5, 0, 0
event_1B9_command_6C1E:
    event_wait_idle 
event_1B9_command_6C1F:
    event_wait 4
