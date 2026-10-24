; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0DA7
.include "src/rom/event_command_macros.inc"
event_400_command_0DA7:
    event_actor_animation_loop 0, 128
event_400_command_0DAA:
    event_wait_idle 
