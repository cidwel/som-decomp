; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2A34
.include "src/rom/event_command_macros.inc"
event_106_command_2A34:
    event_actor_walk 5, 3, 0
event_106_command_2A37:
    event_actor_walk 6, 1, 0
event_106_command_2A3A:
    event_actor_animation_loop 0, 128
