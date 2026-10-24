; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4389
.include "src/rom/event_command_macros.inc"
event_13E_command_4389:
    event_wait 0
