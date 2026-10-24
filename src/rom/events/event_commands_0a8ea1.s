; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8EA1
.include "src/rom/event_command_macros.inc"
event_67F_command_8EA1:
    event_wait 0
