; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E82
.include "src/rom/event_command_macros.inc"
event_67E_command_8E82:
    event_object_command_36 1000
