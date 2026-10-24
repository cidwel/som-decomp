; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B936
.include "src/rom/event_command_macros.inc"
event_2B2_command_B936:
    event_wait 48
event_2B2_command_B938:
    event_wait 0
