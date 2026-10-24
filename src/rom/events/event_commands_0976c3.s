; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $76C3
.include "src/rom/event_command_macros.inc"
event_1CE_command_76C3:
    event_actor_animation_loop 1, 128
event_1CE_command_76C6:
    event_actor_animation_loop 2, 128
event_1CE_command_76C9:
    event_wait_idle 
