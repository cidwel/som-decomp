; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2AB6
.include "src/rom/event_command_macros.inc"
event_106_command_2AB6:
    event_set_flag 1, 4
event_106_command_2AB9:
    event_actor_walk 5, 2, 16
event_106_command_2ABC:
    event_actor_walk 6, 2, 16
event_106_command_2ABF:
    event_wait_idle 
