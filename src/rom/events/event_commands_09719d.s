; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $719D
.include "src/rom/event_command_macros.inc"
event_1C6_command_719D:
    event_set_flag 13, 0
event_1C6_command_71A0:
    event_set_flag 4, 1
event_1C6_command_71A3:
    event_set_flag 22, 0
event_1C6_command_71A6:
    event_delete_actor 1
event_1C6_command_71A8:
    event_actor_walk 0, 1, 0
