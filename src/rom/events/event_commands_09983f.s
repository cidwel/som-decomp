; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $983F
.include "src/rom/event_command_macros.inc"
event_227_command_983F:
    event_wait 0
