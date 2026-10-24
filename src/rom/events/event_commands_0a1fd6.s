; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FD6
.include "src/rom/event_command_macros.inc"
event_4B3_command_1FD6:
    event_actor_walk 4, 2, 0
event_4B3_command_1FD9:
    event_actor_walk 5, 2, 0
event_4B3_command_1FDC:
    event_actor_walk 6, 3, 8
event_4B3_command_1FDF:
    event_wait_idle 
