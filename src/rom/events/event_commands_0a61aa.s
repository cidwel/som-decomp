; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $61AA
.include "src/rom/event_command_macros.inc"
event_532_command_61AA:
    event_wait 0
