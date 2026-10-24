; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $47E5
.include "src/rom/event_command_macros.inc"
event_4E9_command_47E5:
    event_wait 0
