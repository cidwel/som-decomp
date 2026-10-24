; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E101
.include "src/rom/event_command_macros.inc"
event_3A6_command_E101:
    event_jump 935
event_3A6_command_E103:
    event_end 
