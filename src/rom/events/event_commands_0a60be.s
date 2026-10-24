; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $60BE
.include "src/rom/event_command_macros.inc"
event_532_command_60BE:
    event_wait 0
