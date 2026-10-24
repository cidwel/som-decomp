; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E740
.include "src/rom/event_command_macros.inc"
event_3C4_command_E740:
    event_wait 0
