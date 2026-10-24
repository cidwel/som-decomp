; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9AA1
.include "src/rom/event_command_macros.inc"
event_22E_command_9AA1:
    event_actor_walk 2, 2, 0
event_22E_command_9AA4:
    event_wait_idle 
event_22E_command_9AA5:
    event_actor_animation_loop 2, 128
event_22E_command_9AA8:
    event_wait_idle 
