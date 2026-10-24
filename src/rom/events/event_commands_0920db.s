; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $20DB
.include "src/rom/event_command_macros.inc"
event_0EB_command_20DB:
    event_call 252
event_0EB_command_20DD:
    event_world_transition 45
event_0EB_command_20DF:
    event_call 247
event_0EB_command_20E1:
    event_jump 1567
event_0EB_command_20E3:
    event_end 
event_0EC_command_20E4:
    event_object_command_37 50
