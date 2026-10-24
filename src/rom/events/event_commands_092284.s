; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2284
.include "src/rom/event_command_macros.inc"
event_0F3_command_2284:
    event_call 252
event_0F3_command_2286:
    event_world_transition 37
event_0F3_command_2288:
    event_call 247
event_0F3_command_228A:
    event_jump 1565
event_0F3_command_228C:
    event_end 
event_0F4_command_228D:
    event_object_command_37 50
