; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $08EB
.include "src/rom/event_command_macros.inc"
event_010_command_08EB:
    event_wait 0
