; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $83A2
.include "src/rom/event_command_macros.inc"
event_5F8_command_83A2:
    event_wait 32
