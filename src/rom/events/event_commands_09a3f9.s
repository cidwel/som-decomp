; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A3F9
.include "src/rom/event_command_macros.inc"
event_264_command_A3F9:
    event_jump 1535
event_264_command_A3FB:
    event_end 
