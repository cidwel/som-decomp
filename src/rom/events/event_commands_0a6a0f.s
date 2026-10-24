; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6A0F
.include "src/rom/event_command_macros.inc"
event_55E_command_6A0F:
    event_wait 0
