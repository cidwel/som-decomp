; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8D88
.include "src/rom/event_command_macros.inc"
event_66D_command_8D88:
    event_wait 0
