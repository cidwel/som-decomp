; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E0F6
.include "src/rom/event_command_macros.inc"
event_3A5_command_E0F6:
    event_jump 1535
event_3A5_command_E0F8:
    event_end 
