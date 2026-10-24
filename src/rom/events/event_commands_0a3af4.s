; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3AF4
.include "src/rom/event_command_macros.inc"
event_4E4_command_3AF4:
    event_wait 24
