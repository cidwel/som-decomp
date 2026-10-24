; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $38A0
.include "src/rom/event_command_macros.inc"
event_4E3_command_38A0:
    event_wait 0
