; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $424E
.include "src/rom/event_command_macros.inc"
event_13C_command_424E:
    event_wait 0
