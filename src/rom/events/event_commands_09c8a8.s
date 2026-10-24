; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C8A8
.include "src/rom/event_command_macros.inc"
event_2F1_command_C8A8:
    event_jump 1535
event_2F1_command_C8AA:
    event_end 
