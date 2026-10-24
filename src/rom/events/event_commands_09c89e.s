; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C89E
.include "src/rom/event_command_macros.inc"
event_2F0_command_C89E:
    event_jump 1535
event_2F0_command_C8A0:
    event_end 
