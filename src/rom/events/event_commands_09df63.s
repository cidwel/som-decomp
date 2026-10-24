; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DF63
.include "src/rom/event_command_macros.inc"
event_39A_command_DF63:
    event_jump 1535
event_39A_command_DF65:
    event_end 
