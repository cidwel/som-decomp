; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $69A4
.include "src/rom/event_command_macros.inc"
event_55E_command_69A4:
    event_wait 0
