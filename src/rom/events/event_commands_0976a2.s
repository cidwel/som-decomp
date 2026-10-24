; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $76A2
.include "src/rom/event_command_macros.inc"
event_1CE_command_76A2:
    event_call 1941
event_1CE_command_76A4:
    event_actor_animation_loop 1, 170
event_1CE_command_76A7:
    event_actor_animation_loop 2, 170
event_1CE_command_76AA:
    event_wait_idle 
