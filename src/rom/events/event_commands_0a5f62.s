; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5F62
.include "src/rom/event_command_macros.inc"
event_52E_command_5F62:
    event_wait 0
