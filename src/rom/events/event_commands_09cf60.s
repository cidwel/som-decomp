; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CF60
.include "src/rom/event_command_macros.inc"
event_337_command_CF60:
    event_wait 0
