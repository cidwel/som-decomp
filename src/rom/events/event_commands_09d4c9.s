; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D4C9
.include "src/rom/event_command_macros.inc"
event_36D_command_D4C9:
    event_wait 0
