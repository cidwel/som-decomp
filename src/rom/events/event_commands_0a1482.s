; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1482
.include "src/rom/event_command_macros.inc"
event_42D_command_1482:
    event_actor_animation_loop 2, 157
event_42D_command_1485:
    event_wait_idle 
event_42D_command_1486:
    event_wait 48
