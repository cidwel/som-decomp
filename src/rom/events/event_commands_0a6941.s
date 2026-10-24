; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6941
.include "src/rom/event_command_macros.inc"
event_55E_command_6941:
    event_wait 16
