; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $952E
.include "src/rom/event_command_macros.inc"
event_212_command_952E:
    event_increment_flag 89
event_212_command_9530:
    event_end 
