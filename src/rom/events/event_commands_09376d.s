; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $376D
.include "src/rom/event_command_macros.inc"
event_117_command_376D:
    event_jump 1535
event_117_command_376F:
    event_end 
