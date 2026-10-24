; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1BEA
.include "src/rom/event_command_macros.inc"
event_4AA_command_1BEA:
    event_jump 1535
event_4AA_command_1BEC:
    event_end 
