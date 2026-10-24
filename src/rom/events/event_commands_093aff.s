; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3AFF
.include "src/rom/event_command_macros.inc"
event_127_command_3AFF:
    event_wait 0
