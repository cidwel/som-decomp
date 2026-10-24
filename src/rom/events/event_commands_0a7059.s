; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7059
.include "src/rom/event_command_macros.inc"
event_584_command_7059:
    event_wait 16
event_584_command_705B:
    event_wait 0
