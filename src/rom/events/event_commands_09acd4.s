; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ACD4
.include "src/rom/event_command_macros.inc"
event_28F_command_ACD4:
    event_jump 1535
event_28F_command_ACD6:
    event_end 
