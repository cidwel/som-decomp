; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3DBC
.include "src/rom/event_command_macros.inc"
event_4E5_command_3DBC:
    event_wait 0
