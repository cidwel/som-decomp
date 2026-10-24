; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B985
.include "src/rom/event_command_macros.inc"
event_2B3_command_B985:
    event_jump 1535
event_2B3_command_B987:
    event_end 
