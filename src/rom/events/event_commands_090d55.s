; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0D55
.include "src/rom/event_command_macros.inc"
event_02C_command_0D55:
    event_jump 1535
event_02C_command_0D57:
    event_end 
