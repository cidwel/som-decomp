; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EF81
.include "src/rom/event_command_macros.inc"
event_3E7_command_EF81:
    event_jump 1535
event_3E7_command_EF83:
    event_end 
