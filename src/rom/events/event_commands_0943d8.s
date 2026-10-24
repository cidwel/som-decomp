; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $43D8
.include "src/rom/event_command_macros.inc"
event_13E_command_43D8:
    event_wait 0
