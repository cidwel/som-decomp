; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $98AA
.include "src/rom/event_command_macros.inc"
event_228_command_98AA:
    event_wait 4
