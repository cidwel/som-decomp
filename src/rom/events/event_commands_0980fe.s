; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $80FE
.include "src/rom/event_command_macros.inc"
event_1DD_command_80FE:
    event_call 65
event_1DD_command_8100:
    event_jump 1823
event_1DD_command_8102:
    event_end 
