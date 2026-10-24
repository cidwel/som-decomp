; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $743B
.include "src/rom/event_command_macros.inc"
event_1CA_command_743B:
    event_wait 0
