; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D5E8
.include "src/rom/event_command_macros.inc"
event_36F_command_D5E8:
    event_wait 8
