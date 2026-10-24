; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6886
.include "src/rom/event_command_macros.inc"
event_55E_command_6886:
    event_call 92
event_55E_command_6888:
    event_wait 16
