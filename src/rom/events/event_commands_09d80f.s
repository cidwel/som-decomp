; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D80F
.include "src/rom/event_command_macros.inc"
event_378_command_D80F:
    event_wait 0
