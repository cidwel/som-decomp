; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1980
.include "src/rom/event_command_macros.inc"
event_0BB_command_1980:
    event_jump 1535
event_0BB_command_1982:
    event_end 
