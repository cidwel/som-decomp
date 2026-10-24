; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $80EC
.include "src/rom/event_command_macros.inc"
event_5F8_command_80EC:
    event_wait 0
