; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $147F
.include "src/rom/event_command_macros.inc"
event_42D_command_147F:
    event_wait 32
