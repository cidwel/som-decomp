; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1570
.include "src/rom/event_command_macros.inc"
event_0AA_command_1570:
    event_wait 0
