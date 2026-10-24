; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E5F6
.include "src/rom/event_command_macros.inc"
event_3BC_command_E5F6:
    event_jump 1535
event_3BC_command_E5F8:
    event_end 
