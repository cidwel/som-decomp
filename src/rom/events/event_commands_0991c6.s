; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $91C6
.include "src/rom/event_command_macros.inc"
event_208_command_91C6:
    event_wait 0
