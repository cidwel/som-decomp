; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $19F5
.include "src/rom/event_command_macros.inc"
event_0BD_command_19F5:
    event_jump 1535
event_0BD_command_19F7:
    event_end 
