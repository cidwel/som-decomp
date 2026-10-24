; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BAD2
.include "src/rom/event_command_macros.inc"
event_2B8_command_BAD2:
    event_jump 1535
event_2B8_command_BAD4:
    event_end 
