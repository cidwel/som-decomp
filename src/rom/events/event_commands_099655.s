; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9655
.include "src/rom/event_command_macros.inc"
event_21D_command_9655:
    event_jump 1535
event_21D_command_9657:
    event_end 
