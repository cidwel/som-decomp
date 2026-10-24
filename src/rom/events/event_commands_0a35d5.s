; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $35D5
.include "src/rom/event_command_macros.inc"
event_4E2_command_35D5:
    event_wait 0
