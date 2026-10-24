; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DCD5
.include "src/rom/event_command_macros.inc"
event_392_command_DCD5:
    event_jump 1535
event_392_command_DCD7:
    event_end 
