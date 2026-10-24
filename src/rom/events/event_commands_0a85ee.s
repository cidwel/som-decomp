; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85EE
.include "src/rom/event_command_macros.inc"
event_602_command_85EE:
    event_call 1547
