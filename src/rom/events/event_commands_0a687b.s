; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $687B
.include "src/rom/event_command_macros.inc"
event_55E_command_687B:
    event_call 2008
