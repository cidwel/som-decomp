; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3E55
.include "src/rom/event_command_macros.inc"
event_136_command_3E55:
    event_jump 1535
event_136_command_3E57:
    event_end 
