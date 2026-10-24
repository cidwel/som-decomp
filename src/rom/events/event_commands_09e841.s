; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E841
.include "src/rom/event_command_macros.inc"
event_3C8_command_E841:
    event_jump 1535
event_3C8_command_E843:
    event_end 
