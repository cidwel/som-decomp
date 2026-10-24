; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $26AE
.include "src/rom/event_command_macros.inc"
event_103_command_26AE:
    event_wait 4
