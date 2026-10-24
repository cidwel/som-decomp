; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $57A5
.include "src/rom/event_command_macros.inc"
event_181_command_57A5:
    event_wait 0
