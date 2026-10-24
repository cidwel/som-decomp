; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7508
.include "src/rom/event_command_macros.inc"
event_592_command_7508:
    event_wait 24
event_592_command_750A:
    event_actor_walk 3, 3, 0
