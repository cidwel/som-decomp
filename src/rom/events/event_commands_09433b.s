; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $433B
.include "src/rom/event_command_macros.inc"
event_13E_command_433B:
    event_wait 0
