; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1941
.include "src/rom/event_command_macros.inc"
event_4A1_command_1941:
    event_actor_walk 4, 1, 0
event_4A1_command_1944:
    event_wait_idle 
