; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FCF
.include "src/rom/event_command_macros.inc"
event_4B3_command_1FCF:
    event_actor_walk 4, 3, 0
event_4B3_command_1FD2:
    event_wait_idle 
event_4B3_command_1FD3:
    event_wait 0
