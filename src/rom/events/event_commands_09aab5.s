; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AAB5
.include "src/rom/event_command_macros.inc"
event_28B_command_AAB5:
    event_wait 0
