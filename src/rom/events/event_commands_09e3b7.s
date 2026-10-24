; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E3B7
.include "src/rom/event_command_macros.inc"
event_3AE_command_E3B7:
    event_jump 1535
event_3AE_command_E3B9:
    event_end 
