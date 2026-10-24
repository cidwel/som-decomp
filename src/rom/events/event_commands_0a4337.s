; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4337
.include "src/rom/event_command_macros.inc"
event_4E8_command_4337:
    event_wait 0
