; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E1D6
.include "src/rom/event_command_macros.inc"
event_3AA_command_E1D6:
    event_actor_animation_loop 2, 166
event_3AA_command_E1D9:
    event_wait_idle 
