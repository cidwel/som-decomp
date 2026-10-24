; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2068
.include "src/rom/event_command_macros.inc"
event_0E9_command_2068:
    event_call 252
event_0E9_command_206A:
    event_world_transition 48
event_0E9_command_206C:
    event_call 247
event_0E9_command_206E:
    event_jump 1568
event_0E9_command_2070:
    event_end 
event_0EA_command_2071:
    event_object_command_37 50
