; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $152B
.include "src/rom/event_command_macros.inc"
event_42D_command_152B:
    event_wait 0
