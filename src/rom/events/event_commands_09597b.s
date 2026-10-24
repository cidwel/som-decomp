; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $597B
.include "src/rom/event_command_macros.inc"
event_186_command_597B:
    event_wait 0
