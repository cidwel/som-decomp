; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $238C
.include "src/rom/event_command_macros.inc"
event_0F9_command_238C:
    event_jump 1535
event_0F9_command_238E:
    event_end 
