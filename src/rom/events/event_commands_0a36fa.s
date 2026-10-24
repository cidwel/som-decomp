; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $36FA
.include "src/rom/event_command_macros.inc"
event_4E3_command_36FA:
    event_wait 0
