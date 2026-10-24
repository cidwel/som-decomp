; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1447
.include "src/rom/event_command_macros.inc"
event_42D_command_1447:
    event_increment_flag 78
event_42D_command_1449:
    event_call 1864
event_42D_command_144B:
    event_increment_flag 255
event_42D_command_144D:
    event_call 1149
event_42D_command_144F:
    event_actor_animation_loop 2, 128
event_42D_command_1452:
    event_wait_idle 
event_42D_command_1453:
    event_call 1848
