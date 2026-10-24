; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1C37
.include "src/rom/event_command_macros.inc"
event_4AB_command_1C37:
    event_jump 1535
event_4AB_command_1C39:
    event_end 
