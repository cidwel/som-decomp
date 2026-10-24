; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D94F
.include "src/rom/event_command_macros.inc"
event_384_command_D94F:
    event_wait 0
