; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9EF3
.include "src/rom/event_command_macros.inc"
event_24B_command_9EF3:
    event_wait 0
