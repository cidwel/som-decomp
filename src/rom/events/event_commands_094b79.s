; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4B79
.include "src/rom/event_command_macros.inc"
event_15A_command_4B79:
    event_jump 1535
event_15A_command_4B7B:
    event_end 
event_15B_command_4B7C:
    event_end 
