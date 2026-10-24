; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A240
.include "src/rom/event_command_macros.inc"
event_25D_command_A240:
    event_jump 1535
event_25D_command_A242:
    event_end 
