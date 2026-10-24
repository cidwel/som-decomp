; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E6AD
.include "src/rom/event_command_macros.inc"
event_3C1_command_E6AD:
    event_jump 1535
event_3C1_command_E6AF:
    event_end 
