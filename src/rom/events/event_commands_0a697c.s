; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $697C
.include "src/rom/event_command_macros.inc"
event_55E_command_697C:
    event_call 83
event_55E_command_697E:
    event_actor_walk 5, 0, 40
event_55E_command_6981:
    event_actor_walk 6, 0, 40
event_55E_command_6984:
    event_wait_idle 
