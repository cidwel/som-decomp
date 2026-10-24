; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B409
.include "src/rom/event_command_macros.inc"
event_29E_command_B409:
    event_wait 0
