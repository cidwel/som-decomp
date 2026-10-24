; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $76C0
.include "src/rom/event_command_macros.inc"
event_1CE_command_76C0:
    event_wait 0
