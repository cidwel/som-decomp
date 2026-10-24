; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C9D1
.include "src/rom/event_command_macros.inc"
event_2F8_command_C9D1:
    event_jump 1535
event_2F8_command_C9D3:
    event_end 
