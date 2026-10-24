; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F1F3
.include "src/rom/event_command_macros.inc"
event_3EE_command_F1F3:
    event_jump 1535
event_3EE_command_F1F5:
    event_end 
event_3EF_command_F1F6:
    event_call 1008
