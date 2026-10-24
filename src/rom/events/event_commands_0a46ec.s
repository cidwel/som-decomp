; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $46EC
.include "src/rom/event_command_macros.inc"
event_4E9_command_46EC:
    event_wait 0
