; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4353
.include "src/rom/event_command_macros.inc"
event_4E8_command_4353:
    event_call 95
event_4E8_command_4355:
    event_actor_animation_loop 0, 167
