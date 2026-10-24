; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3841
.include "src/rom/event_command_macros.inc"
event_11B_command_3841:
    event_wait 0
