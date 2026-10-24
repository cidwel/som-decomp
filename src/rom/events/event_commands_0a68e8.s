; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68E8
.include "src/rom/event_command_macros.inc"
event_55E_command_68E8:
    event_wait 32
