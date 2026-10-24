; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AC59
.include "src/rom/event_command_macros.inc"
event_28E_command_AC59:
    event_jump 1535
event_28E_command_AC5B:
    event_end 
