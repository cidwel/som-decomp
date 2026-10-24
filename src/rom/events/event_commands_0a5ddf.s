; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5DDF
.include "src/rom/event_command_macros.inc"
event_526_command_5DDF:
    event_wait 0
