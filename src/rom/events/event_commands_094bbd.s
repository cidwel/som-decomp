; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4BBD
.include "src/rom/event_command_macros.inc"
event_15C_command_4BBD:
    event_jump 1535
event_15C_command_4BBF:
    event_end 
