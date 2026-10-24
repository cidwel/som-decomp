; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5BA2
.include "src/rom/event_command_macros.inc"
event_511_command_5BA2:
    event_call 86
