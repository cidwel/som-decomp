; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $73EA
.include "src/rom/event_command_macros.inc"
event_1CA_command_73EA:
    event_wait 0
