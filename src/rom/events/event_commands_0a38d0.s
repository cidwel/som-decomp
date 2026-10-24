; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $38D0
.include "src/rom/event_command_macros.inc"
event_4E3_command_38D0:
    event_wait 0
