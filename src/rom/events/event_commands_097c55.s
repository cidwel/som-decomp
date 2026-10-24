; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7C55
.include "src/rom/event_command_macros.inc"
event_1D5_command_7C55:
    event_jump 1535
event_1D5_command_7C57:
    event_end 
event_1D6_command_7C58:
    event_call 95
