; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C8E0
.include "src/rom/event_command_macros.inc"
event_2F3_command_C8E0:
    event_jump 1535
event_2F3_command_C8E2:
    event_end 
