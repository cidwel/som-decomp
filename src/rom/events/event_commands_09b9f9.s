; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B9F9
.include "src/rom/event_command_macros.inc"
event_2B4_command_B9F9:
    event_jump 1535
event_2B4_command_B9FB:
    event_end 
