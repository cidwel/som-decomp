; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9BC2
.include "src/rom/event_command_macros.inc"
event_236_command_9BC2:
    event_wait 0
