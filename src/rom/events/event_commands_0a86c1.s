; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $86C1
.include "src/rom/event_command_macros.inc"
event_60A_command_86C1:
    event_return 
event_60A_command_86C2:
    event_end 
