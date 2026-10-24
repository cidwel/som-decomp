; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2B81
.include "src/rom/event_command_macros.inc"
event_107_command_2B81:
    event_end 
