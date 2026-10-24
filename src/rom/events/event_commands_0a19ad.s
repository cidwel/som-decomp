; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $19AD
.include "src/rom/event_command_macros.inc"
event_4A1_command_19AD:
    event_wait 0
