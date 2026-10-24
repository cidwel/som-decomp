; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6B88
.include "src/rom/event_command_macros.inc"
event_1B6_command_6B88:
    event_jump 1535
event_1B6_command_6B8A:
    event_end 
