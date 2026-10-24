; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $45D6
.include "src/rom/event_command_macros.inc"
event_4E8_command_45D6:
    event_wait 0
