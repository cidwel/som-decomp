; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $10A1
.include "src/rom/event_command_macros.inc"
event_04F_command_10A1:
    event_jump 80
event_04F_command_10A3:
    event_end 
