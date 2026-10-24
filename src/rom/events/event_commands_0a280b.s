; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $280B
.include "src/rom/event_command_macros.inc"
event_4D0_command_280B:
    event_wait 48
event_4D0_command_280D:
    event_hero_command 73
event_4D0_command_280F:
    event_wait 0
