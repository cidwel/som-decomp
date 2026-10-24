; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A5C4
.include "src/rom/event_command_macros.inc"
event_270_command_A5C4:
    event_jump 1535
event_270_command_A5C6:
    event_end 
