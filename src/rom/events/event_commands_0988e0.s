; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $88E0
.include "src/rom/event_command_macros.inc"
event_1ED_command_88E0:
    event_wait 0
