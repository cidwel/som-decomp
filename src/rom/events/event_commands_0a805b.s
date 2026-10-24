; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $805B
.include "src/rom/event_command_macros.inc"
event_5F8_command_805B:
    event_wait 0
