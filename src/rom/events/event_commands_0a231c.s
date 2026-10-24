; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $231C
.include "src/rom/event_command_macros.inc"
event_4B6_command_231C:
    event_wait 0
