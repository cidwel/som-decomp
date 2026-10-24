; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85F2
.include "src/rom/event_command_macros.inc"
event_602_command_85F2:
    event_jump 1535
event_602_command_85F4:
    event_end 
