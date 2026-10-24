; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7462
.include "src/rom/event_command_macros.inc"
event_592_command_7462:
    event_actor_animation 3, 141
event_592_command_7465:
    event_wait_idle 
event_592_command_7466:
    event_actor_animation_loop 3, 128
event_592_command_7469:
    event_actor_walk 1, 2, 0
event_592_command_746C:
    event_actor_walk 2, 3, 0
event_592_command_746F:
    event_wait_idle 
