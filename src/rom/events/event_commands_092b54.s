; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2B54
.include "src/rom/event_command_macros.inc"
event_107_command_2B54:
    event_wait 0
