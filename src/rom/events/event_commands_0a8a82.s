; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A82
.include "src/rom/event_command_macros.inc"
event_66B_command_8A82:
    event_wait 24
