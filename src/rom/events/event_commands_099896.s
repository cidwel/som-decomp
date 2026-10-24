; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9896
.include "src/rom/event_command_macros.inc"
event_228_command_9896:
    event_wait 4
