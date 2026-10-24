; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C7AD
.include "src/rom/event_command_macros.inc"
event_2EA_command_C7AD:
    event_jump 1535
event_2EA_command_C7AF:
    event_end 
