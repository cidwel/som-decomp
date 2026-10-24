; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E86
.include "src/rom/event_command_macros.inc"
event_67E_command_8E86:
    event_wait 0
