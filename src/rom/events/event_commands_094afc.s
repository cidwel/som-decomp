; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4AFC
.include "src/rom/event_command_macros.inc"
event_159_command_4AFC:
    event_wait 0
