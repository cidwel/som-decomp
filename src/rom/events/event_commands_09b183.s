; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B183
.include "src/rom/event_command_macros.inc"
event_29C_command_B183:
    event_actor_walk 5, 1, 0
event_29C_command_B186:
    event_wait_idle 
