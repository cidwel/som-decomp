; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B544
.include "src/rom/event_command_macros.inc"
event_2A4_command_B544:
    event_jump 1535
event_2A4_command_B546:
    event_end 
event_2A5_command_B547:
    event_call 681
event_2A5_command_B549:
    event_end 
