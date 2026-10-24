; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8711
.include "src/rom/event_command_macros.inc"
event_1EB_command_8711:
    event_call 490
