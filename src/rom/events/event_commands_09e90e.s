; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E90E
.include "src/rom/event_command_macros.inc"
event_3CD_command_E90E:
    event_jump 1535
event_3CD_command_E910:
    event_end 
