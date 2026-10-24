; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $599B
.include "src/rom/event_command_macros.inc"
event_509_command_599B:
    event_return 
event_509_command_599C:
    event_end 
event_50A_command_599D:
    event_wait 0
