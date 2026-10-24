; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DE06
.include "src/rom/event_command_macros.inc"
event_397_command_DE06:
    event_wait 48
event_397_command_DE08:
    event_wait 0
