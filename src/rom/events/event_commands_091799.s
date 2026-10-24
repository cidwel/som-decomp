; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1799
.include "src/rom/event_command_macros.inc"
event_0B3_command_1799:
    event_jump 1535
event_0B3_command_179B:
    event_end 
