; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $59CC
.include "src/rom/event_command_macros.inc"
event_186_command_59CC:
    event_wait 0
