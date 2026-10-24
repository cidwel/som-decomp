; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CCC8
.include "src/rom/event_command_macros.inc"
event_311_command_CCC8:
    event_wait 0
