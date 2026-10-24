; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7254
.include "src/rom/event_command_macros.inc"
event_587_command_7254:
    event_wait 16
event_587_command_7256:
    event_wait 0
