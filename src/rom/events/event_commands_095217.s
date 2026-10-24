; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5217
.include "src/rom/event_command_macros.inc"
event_16E_command_5217:
    event_wait 0
