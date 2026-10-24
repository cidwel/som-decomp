; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4AC4
.include "src/rom/event_command_macros.inc"
event_158_command_4AC4:
    event_jump 1535
event_158_command_4AC6:
    event_end 
