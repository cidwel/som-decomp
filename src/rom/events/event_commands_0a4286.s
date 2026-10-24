; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4286
.include "src/rom/event_command_macros.inc"
event_4E8_command_4286:
    event_call 1854
event_4E8_command_4288:
    event_set_actor_field 128, 144, 0
event_4E8_command_428C:
    event_set_actor_field 128, 145, 0
event_4E8_command_4290:
    event_restore_hero 64
event_4E8_command_4292:
    event_change_map 4
event_4E8_command_4294:
    event_call 299
event_4E8_command_4296:
    event_wait_idle 
event_4E8_command_4297:
    event_wait 8
event_4E8_command_4299:
    event_call 300
event_4E8_command_429B:
    event_wait_idle 
event_4E8_command_429C:
    event_wait 8
event_4E8_command_429E:
    event_call 299
event_4E8_command_42A0:
    event_actor_walk 0, 0, 49
event_4E8_command_42A3:
    event_wait_idle 
event_4E8_command_42A4:
    event_call 300
event_4E8_command_42A6:
    event_actor_walk 0, 0, 49
event_4E8_command_42A9:
    event_wait_idle 
event_4E8_command_42AA:
    event_actor_walk 0, 1, 0
event_4E8_command_42AD:
    event_wait_idle 
event_4E8_command_42AE:
    event_call 1855
event_4E8_command_42B0:
    event_screen 8
event_4E8_command_42B2:
    event_toggle_visibility_05 
event_4E8_command_42B3:
    event_call 95
