; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $09F3
.include "src/rom/event_command_macros.inc"
event_020_command_09F3:
    event_jump 1535
event_020_command_09F5:
    event_end 
event_021_command_09F6:
    event_call 31
