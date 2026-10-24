; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $769F
.include "src/rom/event_command_macros.inc"
event_1CE_command_769F:
    event_wait 8
