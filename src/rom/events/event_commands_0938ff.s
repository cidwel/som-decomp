; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $38FF
.include "src/rom/event_command_macros.inc"
event_120_command_38FF:
    event_actor_walk 4, 2, 0
event_120_command_3902:
    event_wait_idle 
event_120_command_3903:
    event_actor_walk 4, 0, 0
event_120_command_3906:
    event_wait_idle 
event_120_command_3907:
    event_actor_walk 4, 3, 0
event_120_command_390A:
    event_wait_idle 
event_120_command_390B:
    event_wait 0
