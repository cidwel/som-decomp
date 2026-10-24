; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E99D
.include "src/rom/event_command_macros.inc"
event_3CF_command_E99D:
    event_jump 1535
event_3CF_command_E99F:
    event_end 
