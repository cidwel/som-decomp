; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E413
.include "src/rom/event_command_macros.inc"
event_3B0_command_E413:
    event_jump 1535
event_3B0_command_E415:
    event_end 
