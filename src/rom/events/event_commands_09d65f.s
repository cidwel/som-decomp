; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D65F
.include "src/rom/event_command_macros.inc"
event_36F_command_D65F:
    event_wait 0
