; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8DBA
.include "src/rom/event_command_macros.inc"
event_66D_command_8DBA:
    event_wait 0
