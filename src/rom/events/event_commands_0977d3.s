; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $77D3
.include "src/rom/event_command_macros.inc"
event_1CE_command_77D3:
    event_wait 0
