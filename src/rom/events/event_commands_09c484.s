; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C484
.include "src/rom/event_command_macros.inc"
event_2DC_command_C484:
    event_wait 0
