; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C94E
.include "src/rom/event_command_macros.inc"
event_2F5_command_C94E:
    event_jump 1535
event_2F5_command_C950:
    event_end 
