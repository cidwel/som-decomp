; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8DF6
.include "src/rom/event_command_macros.inc"
event_66E_command_8DF6:
    event_wait 32
