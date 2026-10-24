; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $345D
.include "src/rom/event_command_macros.inc"
event_4E2_command_345D:
    event_wait 0
