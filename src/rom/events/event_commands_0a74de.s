; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $74DE
.include "src/rom/event_command_macros.inc"
event_592_command_74DE:
    event_wait 0
