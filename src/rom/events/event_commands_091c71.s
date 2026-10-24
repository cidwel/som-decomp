; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1C71
.include "src/rom/event_command_macros.inc"
event_0D3_command_1C71:
    event_jump 1535
event_0D3_command_1C73:
    event_end 
