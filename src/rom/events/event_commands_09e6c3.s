; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E6C3
.include "src/rom/event_command_macros.inc"
event_3C2_command_E6C3:
    event_jump 1535
event_3C2_command_E6C5:
    event_end 
