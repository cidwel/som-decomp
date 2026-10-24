; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B9F
.include "src/rom/event_command_macros.inc"
event_511_command_5B9F:
    event_wait 0
