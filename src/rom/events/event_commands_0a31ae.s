; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $31AE
.include "src/rom/event_command_macros.inc"
event_4E1_command_31AE:
    event_wait 0
