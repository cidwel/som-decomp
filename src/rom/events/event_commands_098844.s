; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8844
.include "src/rom/event_command_macros.inc"
event_1ED_command_8844:
    event_wait 0
