; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0A89
.include "src/rom/event_command_macros.inc"
event_022_command_0A89:
    event_jump 1535
event_022_command_0A8B:
    event_end 
event_023_command_0A8C:
    event_call 31
