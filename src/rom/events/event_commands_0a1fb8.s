; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FB8
.include "src/rom/event_command_macros.inc"
event_4B3_command_1FB8:
    event_actor_walk 4, 2, 0
event_4B3_command_1FBB:
    event_wait_idle 
