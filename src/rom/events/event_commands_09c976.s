; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C976
.include "src/rom/event_command_macros.inc"
event_2F6_command_C976:
    event_jump 1535
event_2F6_command_C978:
    event_end 
