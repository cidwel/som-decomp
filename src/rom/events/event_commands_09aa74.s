; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AA74
.include "src/rom/event_command_macros.inc"
event_28B_command_AA74:
    event_actor_animation_loop 3, 166
event_28B_command_AA77:
    event_wait_idle 
