; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $987D
.include "src/rom/event_command_macros.inc"
event_227_command_987D:
    event_call 89
event_227_command_987F:
    event_end 
