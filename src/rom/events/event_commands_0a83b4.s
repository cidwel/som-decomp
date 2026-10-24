; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $83B4
.include "src/rom/event_command_macros.inc"
event_5F8_command_83B4:
    event_call 1927
event_5F8_command_83B6:
    event_actor_animation 3, 130
event_5F8_command_83B9:
    event_wait_idle 
