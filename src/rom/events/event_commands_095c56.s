; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5C56
.include "src/rom/event_command_macros.inc"
event_18C_command_5C56:
    event_jump 1535
event_18C_command_5C58:
    event_end 
