; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $645F
.include "src/rom/event_command_macros.inc"
event_555_command_645F:
    event_wait 0
