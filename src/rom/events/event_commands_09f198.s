; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F198
.include "src/rom/event_command_macros.inc"
event_3ED_command_F198:
    event_jump 1535
event_3ED_command_F19A:
    event_end 
event_3EE_command_F19B:
    event_call 1008
