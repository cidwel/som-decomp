; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2192
.include "src/rom/event_command_macros.inc"
event_0EE_command_2192:
    event_call 252
event_0EE_command_2194:
    event_world_transition 39
event_0EE_command_2196:
    event_call 247
event_0EE_command_2198:
    event_jump 1552
event_0EE_command_219A:
    event_end 
event_0EF_command_219B:
    event_object_command_37 50
