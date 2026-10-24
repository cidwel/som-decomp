; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $13CE
.include "src/rom/event_command_macros.inc"
event_083_command_13CE:
    event_call 1040
event_083_command_13D0:
    event_call 1927
event_083_command_13D2:
    event_actor_animation 1, 141
event_083_command_13D5:
    event_actor_animation 2, 141
event_083_command_13D8:
    event_actor_animation 3, 141
event_083_command_13DB:
    event_wait_idle 
