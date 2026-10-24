; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $263A
.include "src/rom/event_command_macros.inc"
event_103_command_263A:
    event_wait 4
event_103_command_263C:
    event_screen 7
event_103_command_263E:
    event_wait 16
