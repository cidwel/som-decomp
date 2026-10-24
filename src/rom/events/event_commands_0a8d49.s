; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8D49
.include "src/rom/event_command_macros.inc"
event_66D_command_8D49:
    event_wait 0
