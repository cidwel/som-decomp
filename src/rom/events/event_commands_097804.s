; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7804
.include "src/rom/event_command_macros.inc"
event_1CE_command_7804:
    event_call 86
event_1CE_command_7806:
    event_wait 16
