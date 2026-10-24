; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $711E
.include "src/rom/event_command_macros.inc"
event_586_command_711E:
    event_wait 0
