; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B20F
.include "src/rom/event_command_macros.inc"
event_29C_command_B20F:
    event_actor_animation_loop 4, 138
event_29C_command_B212:
    event_wait_idle 
event_29C_command_B213:
    event_wait 1
event_29C_command_B215:
    event_actor_animation_loop 4, 128
event_29C_command_B218:
    event_wait_idle 
