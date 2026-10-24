; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85A2
.include "src/rom/event_command_macros.inc"
event_5FF_command_85A2:
    event_end 
