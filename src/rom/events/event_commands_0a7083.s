; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7083
.include "src/rom/event_command_macros.inc"
event_585_command_7083:
    event_wait 16
event_585_command_7085:
    event_wait 0
