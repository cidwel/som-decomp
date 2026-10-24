; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $874E
.include "src/rom/event_command_macros.inc"
event_1EC_command_874E:
    event_wait 0
