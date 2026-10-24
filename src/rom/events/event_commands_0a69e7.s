; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $69E7
.include "src/rom/event_command_macros.inc"
event_55E_command_69E7:
    event_wait 0
