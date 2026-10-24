; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DFBF
.include "src/rom/event_command_macros.inc"
event_39C_command_DFBF:
    event_jump 1535
event_39C_command_DFC1:
    event_end 
event_39D_command_DFC2:
    event_end 
