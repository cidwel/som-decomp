; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $86D5
.include "src/rom/event_command_macros.inc"
event_60B_command_86D5:
    event_return 
event_60B_command_86D6:
    event_end 
