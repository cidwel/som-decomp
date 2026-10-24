; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5D2C
.include "src/rom/event_command_macros.inc"
event_18F_command_5D2C:
    event_jump 1535
event_18F_command_5D2E:
    event_end 
