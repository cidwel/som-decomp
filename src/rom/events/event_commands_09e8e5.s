; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E8E5
.include "src/rom/event_command_macros.inc"
event_3CC_command_E8E5:
    event_jump 1535
event_3CC_command_E8E7:
    event_end 
