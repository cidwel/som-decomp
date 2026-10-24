; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7468
.include "src/rom/event_command_macros.inc"
event_1CA_command_7468:
    event_wait 0
