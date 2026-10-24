; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A359
.include "src/rom/event_command_macros.inc"
event_263_command_A359:
    event_jump 1535
event_263_command_A35B:
    event_end 
