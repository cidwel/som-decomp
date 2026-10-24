; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B89A
.include "src/rom/event_command_macros.inc"
event_2B1_command_B89A:
    event_jump 1535
event_2B1_command_B89C:
    event_end 
