; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3C0D
.include "src/rom/event_command_macros.inc"
event_4E4_command_3C0D:
    event_wait 0
