; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F0A2
.include "src/rom/event_command_macros.inc"
event_3EA_command_F0A2:
    event_jump 1535
event_3EA_command_F0A4:
    event_end 
event_3EB_command_F0A5:
    event_call 1008
