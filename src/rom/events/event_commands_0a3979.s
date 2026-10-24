; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3979
.include "src/rom/event_command_macros.inc"
event_4E4_command_3979:
    event_call 1947
event_4E4_command_397B:
    event_wait 32
event_4E4_command_397D:
    event_call 1947
event_4E4_command_397F:
    event_wait 32
event_4E4_command_3981:
    event_actor_walk 2, 2, 0
event_4E4_command_3984:
    event_wait_idle 
