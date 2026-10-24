; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EE2C
.include "src/rom/event_command_macros.inc"
event_3E2_command_EE2C:
    event_jump 1535
event_3E2_command_EE2E:
    event_end 
