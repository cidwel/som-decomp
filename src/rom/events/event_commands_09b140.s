; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B140
.include "src/rom/event_command_macros.inc"
event_29C_command_B140:
    event_actor_walk 4, 3, 0
event_29C_command_B143:
    event_wait_idle 
event_29C_command_B144:
    event_actor_animation_loop 4, 131
event_29C_command_B147:
    event_wait_idle 
