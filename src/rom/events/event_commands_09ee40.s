; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EE40
.include "src/rom/event_command_macros.inc"
event_3E3_command_EE40:
    event_jump 1535
event_3E3_command_EE42:
    event_end 
