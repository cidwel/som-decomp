; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BB6C
.include "src/rom/event_command_macros.inc"
event_2BC_command_BB6C:
    event_jump 574
event_2BC_command_BB6E:
    event_end 
