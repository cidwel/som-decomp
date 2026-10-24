; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $420F
.include "src/rom/event_command_macros.inc"
event_4E7_command_420F:
    event_wait 0
