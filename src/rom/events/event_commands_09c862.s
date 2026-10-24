; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C862
.include "src/rom/event_command_macros.inc"
event_2EE_command_C862:
    event_jump 1535
event_2EE_command_C864:
    event_end 
