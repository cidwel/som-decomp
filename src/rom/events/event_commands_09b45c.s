; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B45C
.include "src/rom/event_command_macros.inc"
event_2A2_command_B45C:
    event_jump 1535
event_2A2_command_B45E:
    event_end 
