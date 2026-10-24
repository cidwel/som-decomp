; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B352
.include "src/rom/event_command_macros.inc"
event_29C_command_B352:
    event_wait 0
