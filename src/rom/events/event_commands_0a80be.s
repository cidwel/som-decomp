; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $80BE
.include "src/rom/event_command_macros.inc"
event_5F8_command_80BE:
    event_actor_animation_loop 1, 164
event_5F8_command_80C1:
    event_wait_idle 
