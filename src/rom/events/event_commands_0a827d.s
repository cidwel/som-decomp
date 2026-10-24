; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $827D
.include "src/rom/event_command_macros.inc"
event_5F8_command_827D:
    event_wait 0
event_5F8_command_827F:
    event_wait 32
