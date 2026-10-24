; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $82C7
.include "src/rom/event_command_macros.inc"
event_1E5_command_82C7:
    event_wait 0
