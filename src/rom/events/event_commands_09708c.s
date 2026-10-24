; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $708C
.include "src/rom/event_command_macros.inc"
event_1C2_command_708C:
    event_jump 1535
event_1C2_command_708E:
    event_end 
