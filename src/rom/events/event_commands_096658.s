; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6658
.include "src/rom/event_command_macros.inc"
event_1B2_command_6658:
    event_wait 0
