; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E1B3
.include "src/rom/event_command_macros.inc"
event_3AA_command_E1B3:
    event_actor_walk 1, 0, 4
event_3AA_command_E1B6:
    event_wait_idle 
event_3AA_command_E1B7:
    event_call 88
