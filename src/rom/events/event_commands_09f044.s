; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F044
.include "src/rom/event_command_macros.inc"
event_3E9_command_F044:
    event_jump 1535
event_3E9_command_F046:
    event_end 
event_3EA_command_F047:
    event_call 1008
