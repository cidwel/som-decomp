; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6061
.include "src/rom/event_command_macros.inc"
event_530_command_6061:
    event_jump 1535
event_530_command_6063:
    event_end 
