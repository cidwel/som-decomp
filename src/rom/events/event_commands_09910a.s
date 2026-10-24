; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $910A
.include "src/rom/event_command_macros.inc"
event_205_command_910A:
    event_wait 0
