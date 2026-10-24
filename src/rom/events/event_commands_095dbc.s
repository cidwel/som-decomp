; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5DBC
.include "src/rom/event_command_macros.inc"
event_192_command_5DBC:
    event_wait 0
