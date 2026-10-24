; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B204
.include "src/rom/event_command_macros.inc"
event_29C_command_B204:
    event_actor_walk 4, 1, 0
event_29C_command_B207:
    event_wait_idle 
event_29C_command_B208:
    event_actor_animation_loop 4, 166
event_29C_command_B20B:
    event_wait_idle 
event_29C_command_B20C:
    event_wait 0
