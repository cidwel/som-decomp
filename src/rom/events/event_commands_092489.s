; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2489
.include "src/rom/event_command_macros.inc"
event_0FC_command_2489:
    event_wait 0
