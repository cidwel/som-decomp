; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E9D
.include "src/rom/event_command_macros.inc"
event_67F_command_8E9D:
    event_object_command_36 50
