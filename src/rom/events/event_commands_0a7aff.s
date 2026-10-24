; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7AFF
.include "src/rom/event_command_macros.inc"
event_5F8_command_7AFF:
    event_wait 48
