; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D204
.include "src/rom/event_command_macros.inc"
event_363_command_D204:
    event_wait 0
