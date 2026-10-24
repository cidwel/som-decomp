; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4672
.include "src/rom/event_command_macros.inc"
event_4E8_command_4672:
    event_actor_animation_loop 0, 128
event_4E8_command_4675:
    event_screen 8
