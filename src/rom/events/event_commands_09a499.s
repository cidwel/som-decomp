; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A499
.include "src/rom/event_command_macros.inc"
event_268_command_A499:
    event_jump 1535
event_268_command_A49B:
    event_end 
