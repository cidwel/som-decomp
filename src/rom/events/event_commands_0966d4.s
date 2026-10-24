; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $66D4
.include "src/rom/event_command_macros.inc"
event_1B2_command_66D4:
    event_actor_animation_loop 1, 128
event_1B2_command_66D7:
    event_actor_animation_loop 2, 128
event_1B2_command_66DA:
    event_wait_idle 
