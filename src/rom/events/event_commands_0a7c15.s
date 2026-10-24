; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7C15
.include "src/rom/event_command_macros.inc"
event_5F8_command_7C15:
    event_call 86
event_5F8_command_7C17:
    event_wait 32
event_5F8_command_7C19:
    event_actor_walk 4, 1, 0
event_5F8_command_7C1C:
    event_actor_walk 5, 1, 0
event_5F8_command_7C1F:
    event_actor_walk 6, 1, 0
event_5F8_command_7C22:
    event_wait_idle 
event_5F8_command_7C23:
    event_call 1837
event_5F8_command_7C25:
    event_screen_word 6, 32767
event_5F8_command_7C29:
    event_wait 32
event_5F8_command_7C2B:
    event_set_flag 70, 7
event_5F8_command_7C2E:
    event_refresh_objects 
event_5F8_command_7C2F:
    event_actor_walk 0, 1, 40
event_5F8_command_7C32:
    event_wait_idle 
event_5F8_command_7C33:
    event_gather 
event_5F8_command_7C34:
    event_actor_walk 1, 0, 0
event_5F8_command_7C37:
    event_actor_walk 2, 3, 8
event_5F8_command_7C3A:
    event_actor_walk 3, 2, 8
event_5F8_command_7C3D:
    event_wait_idle 
event_5F8_command_7C3E:
    event_actor_walk 2, 1, 8
event_5F8_command_7C41:
    event_actor_walk 3, 1, 8
event_5F8_command_7C44:
    event_wait_idle 
event_5F8_command_7C45:
    event_actor_walk 2, 0, 0
event_5F8_command_7C48:
    event_actor_walk 3, 0, 0
event_5F8_command_7C4B:
    event_wait_idle 
event_5F8_command_7C4C:
    event_toggle_visibility_05 
event_5F8_command_7C4D:
    event_screen 7
event_5F8_command_7C4F:
    event_wait 32
event_5F8_command_7C51:
    event_increment_flag 248
