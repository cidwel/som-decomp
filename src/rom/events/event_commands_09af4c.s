; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AF4C
.include "src/rom/event_command_macros.inc"
event_295_command_AF4C:
    event_actor_animation_loop 4, 170
event_295_command_AF4F:
    event_wait_idle 
