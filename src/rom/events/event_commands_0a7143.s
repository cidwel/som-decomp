; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7143
.include "src/rom/event_command_macros.inc"
event_586_command_7143:
    event_wait 16
event_586_command_7145:
    event_wait 0
