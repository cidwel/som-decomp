; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7413
.include "src/rom/event_command_macros.inc"
event_592_command_7413:
    event_actor_walk 1, 1, 16
event_592_command_7416:
    event_actor_walk 2, 1, 16
event_592_command_7419:
    event_actor_walk 3, 1, 16
event_592_command_741C:
    event_wait_idle 
event_592_command_741D:
    event_screen 8
event_592_command_741F:
    event_actor_walk 1, 1, 24
event_592_command_7422:
    event_actor_walk 2, 1, 24
event_592_command_7425:
    event_wait_idle 
event_592_command_7426:
    event_actor_walk 1, 3, 12
event_592_command_7429:
    event_actor_walk 2, 2, 12
event_592_command_742C:
    event_wait_idle 
event_592_command_742D:
    event_actor_walk 1, 0, 0
event_592_command_7430:
    event_actor_walk 2, 0, 0
event_592_command_7433:
    event_wait_idle 
