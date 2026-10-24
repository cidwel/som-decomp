; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DFEE
.include "src/rom/event_command_macros.inc"
event_39E_command_DFEE:
    event_jump 1535
event_39E_command_DFF0:
    event_end 
