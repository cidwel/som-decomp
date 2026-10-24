; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D374
.include "src/rom/event_command_macros.inc"
event_367_command_D374:
    event_wait 0
