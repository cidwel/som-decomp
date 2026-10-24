; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $36F7
.include "src/rom/event_command_macros.inc"
event_115_command_36F7:
    event_jump 1535
event_115_command_36F9:
    event_end 
