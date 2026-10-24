; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A102
.include "src/rom/event_command_macros.inc"
event_258_command_A102:
    event_increment_flag 33
