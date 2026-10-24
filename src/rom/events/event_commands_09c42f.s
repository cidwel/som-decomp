; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C42F
.include "src/rom/event_command_macros.inc"
event_2DB_command_C42F:
    event_jump 1535
event_2DB_command_C431:
    event_end 
