; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $212F
.include "src/rom/event_command_macros.inc"
event_0EC_command_212F:
    event_call 252
event_0EC_command_2131:
    event_world_transition 36
event_0EC_command_2133:
    event_call 247
event_0EC_command_2135:
    event_jump 1566
event_0EC_command_2137:
    event_end 
event_0ED_command_2138:
    event_object_command_37 50
