; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C8B3
.include "src/rom/event_command_macros.inc"
event_2F2_command_C8B3:
    event_jump 1535
event_2F2_command_C8B5:
    event_end 
