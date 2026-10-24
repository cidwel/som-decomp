; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1CAF
.include "src/rom/event_command_macros.inc"
event_0D4_command_1CAF:
    event_return 
event_0D4_command_1CB0:
    event_end 
