; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7978
.include "src/rom/event_command_macros.inc"
event_1D3_command_7978:
    event_wait 0
