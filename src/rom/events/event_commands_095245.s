; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5245
.include "src/rom/event_command_macros.inc"
event_16E_command_5245:
    event_wait 8
event_16E_command_5247:
    event_increment_flag 248
