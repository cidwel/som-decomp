; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C4F7
.include "src/rom/event_command_macros.inc"
event_2DD_command_C4F7:
    event_jump 1535
event_2DD_command_C4F9:
    event_end 
