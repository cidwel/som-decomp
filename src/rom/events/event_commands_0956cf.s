; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $56CF
.include "src/rom/event_command_macros.inc"
event_180_command_56CF:
    event_wait 0
