; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1460
.include "src/rom/event_command_macros.inc"
event_42D_command_1460:
    event_wait 32
event_42D_command_1462:
    event_actor_animation_loop 2, 138
event_42D_command_1465:
    event_wait_idle 
event_42D_command_1466:
    event_wait 2
event_42D_command_1468:
    event_actor_animation_loop 2, 128
event_42D_command_146B:
    event_wait_idle 
