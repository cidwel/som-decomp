; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E7D0
.include "src/rom/event_command_macros.inc"
event_3C7_command_E7D0:
    event_jump 1535
event_3C7_command_E7D2:
    event_end 
