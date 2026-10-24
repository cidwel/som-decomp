; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E6E2
.include "src/rom/event_command_macros.inc"
event_3C3_command_E6E2:
    event_jump 1535
event_3C3_command_E6E4:
    event_end 
