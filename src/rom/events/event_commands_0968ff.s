; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68FF
.include "src/rom/event_command_macros.inc"
event_1B5_command_68FF:
    event_wait 0
