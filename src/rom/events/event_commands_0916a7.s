; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $16A7
.include "src/rom/event_command_macros.inc"
event_0B1_command_16A7:
    event_jump 1535
event_0B1_command_16A9:
    event_end 
