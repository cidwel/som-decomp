; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F090
.include "src/rom/event_command_macros.inc"
event_3EA_command_F090:
    event_call 1941
event_3EA_command_F092:
    event_wait 0
