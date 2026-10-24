; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $265F
.include "src/rom/event_command_macros.inc"
event_4C8_command_265F:
    event_wait 0
