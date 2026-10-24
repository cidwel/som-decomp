; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $241D
.include "src/rom/event_command_macros.inc"
event_4B6_command_241D:
    event_wait 0
