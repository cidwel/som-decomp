; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $609F
.include "src/rom/event_command_macros.inc"
event_198_command_609F:
    event_wait 0
