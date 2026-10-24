; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AFAB
.include "src/rom/event_command_macros.inc"
event_296_command_AFAB:
    event_wait 0
