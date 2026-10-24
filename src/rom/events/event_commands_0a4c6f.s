; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4C6F
.include "src/rom/event_command_macros.inc"
event_4EA_command_4C6F:
    event_wait 0
