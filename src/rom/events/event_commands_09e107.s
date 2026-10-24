; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E107
.include "src/rom/event_command_macros.inc"
event_3A7_command_E107:
    event_call 82
event_3A7_command_E109:
    event_call 96
event_3A7_command_E10B:
    event_actor_walk 128, 2, 16
event_3A7_command_E10E:
    event_wait_idle 
event_3A7_command_E10F:
    event_actor_walk 128, 3, 0
event_3A7_command_E112:
    event_wait_idle 
