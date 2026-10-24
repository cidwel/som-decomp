; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $28B3
.include "src/rom/event_command_macros.inc"
event_4E0_command_28B3:
    event_wait 0
