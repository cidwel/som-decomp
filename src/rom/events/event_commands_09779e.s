; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $779E
.include "src/rom/event_command_macros.inc"
event_1CE_command_779E:
    event_wait 0
