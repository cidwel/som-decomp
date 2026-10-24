; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BB0A
.include "src/rom/event_command_macros.inc"
event_2B9_command_BB0A:
    event_jump 1535
event_2B9_command_BB0C:
    event_end 
