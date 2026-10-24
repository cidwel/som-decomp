; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0C0D
.include "src/rom/event_command_macros.inc"
event_027_command_0C0D:
    event_wait 0
