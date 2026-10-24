; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E24D
.include "src/rom/event_command_macros.inc"
event_3AA_command_E24D:
    event_actor_walk 2, 0, 0
event_3AA_command_E250:
    event_wait_idle 
