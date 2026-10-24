; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9E00
.include "src/rom/event_command_macros.inc"
event_23D_command_9E00:
    event_wait 0
