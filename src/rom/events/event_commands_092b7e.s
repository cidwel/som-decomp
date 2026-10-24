; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2B7E
.include "src/rom/event_command_macros.inc"
event_107_command_2B7E:
    event_wait 0
