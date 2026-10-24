; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $271C
.include "src/rom/event_command_macros.inc"
event_103_command_271C:
    event_wait 2
