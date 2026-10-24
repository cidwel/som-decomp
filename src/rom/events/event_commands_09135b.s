; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $135B
.include "src/rom/event_command_macros.inc"
event_081_command_135B:
    event_wait 0
