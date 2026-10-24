; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E18
.include "src/rom/event_command_macros.inc"
event_66F_command_8E18:
    event_wait 16
