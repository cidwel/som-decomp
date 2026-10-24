; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9891
.include "src/rom/event_command_macros.inc"
event_228_command_9891:
    event_wait 8
