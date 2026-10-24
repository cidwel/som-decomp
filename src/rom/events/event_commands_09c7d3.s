; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C7D3
.include "src/rom/event_command_macros.inc"
event_2EB_command_C7D3:
    event_jump 1535
event_2EB_command_C7D5:
    event_end 
