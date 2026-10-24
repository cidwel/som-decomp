; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6BB2
.include "src/rom/event_command_macros.inc"
event_580_command_6BB2:
    event_wait 16
event_580_command_6BB4:
    event_wait 0
event_580_command_6BB6:
    event_call 2003
