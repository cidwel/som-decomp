; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A123
.include "src/rom/event_command_macros.inc"
event_258_command_A123:
    event_call 1040
event_258_command_A125:
    event_actor_animation 3, 141
event_258_command_A128:
    event_wait_idle 
