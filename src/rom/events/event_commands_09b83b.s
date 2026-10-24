; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B83B
.include "src/rom/event_command_macros.inc"
event_2B0_command_B83B:
    event_jump 1535
event_2B0_command_B83D:
    event_end 
