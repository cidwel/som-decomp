; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4B2A
.include "src/rom/event_command_macros.inc"
event_159_command_4B2A:
    event_jump 1535
event_159_command_4B2C:
    event_end 
