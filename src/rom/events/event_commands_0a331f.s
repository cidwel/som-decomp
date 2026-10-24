; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $331F
.include "src/rom/event_command_macros.inc"
event_4E2_command_331F:
    event_actor_walk 128, 3, 0
event_4E2_command_3322:
    event_actor_animation_loop 3, 167
event_4E2_command_3325:
    event_wait_idle 
