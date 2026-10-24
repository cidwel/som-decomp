; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4FC6
.include "src/rom/event_command_macros.inc"
event_16D_command_4FC6:
    event_wait 0
