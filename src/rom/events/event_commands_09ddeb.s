; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DDEB
.include "src/rom/event_command_macros.inc"
event_397_command_DDEB:
    event_wait 0
