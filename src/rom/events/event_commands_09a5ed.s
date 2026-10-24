; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A5ED
.include "src/rom/event_command_macros.inc"
event_271_command_A5ED:
    event_jump 1535
event_271_command_A5EF:
    event_end 
