; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2641
.include "src/rom/event_command_macros.inc"
event_103_command_2641:
    event_call 301
event_103_command_2643:
    event_actor_walk 0, 0, 0
