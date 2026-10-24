; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68A1
.include "src/rom/event_command_macros.inc"
event_55E_command_68A1:
    event_wait 0
