; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E170
.include "src/rom/event_command_macros.inc"
event_3AA_command_E170:
    event_actor_walk 4, 1, 16
event_3AA_command_E173:
    event_wait_idle 
