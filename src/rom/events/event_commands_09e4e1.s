; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E4E1
.include "src/rom/event_command_macros.inc"
event_3B5_command_E4E1:
    event_jump 1535
event_3B5_command_E4E3:
    event_end 
