; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $73A2
.include "src/rom/event_command_macros.inc"
event_1CA_command_73A2:
    event_wait 0
