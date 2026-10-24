; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0CAD
.include "src/rom/event_command_macros.inc"
event_02A_command_0CAD:
    event_jump 1535
event_02A_command_0CAF:
    event_end 
