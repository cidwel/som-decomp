; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $49C1
.include "src/rom/event_command_macros.inc"
event_155_command_49C1:
    event_jump 1535
event_155_command_49C3:
    event_end 
