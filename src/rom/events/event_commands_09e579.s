; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E579
.include "src/rom/event_command_macros.inc"
event_3B9_command_E579:
    event_jump 1535
event_3B9_command_E57B:
    event_end 
