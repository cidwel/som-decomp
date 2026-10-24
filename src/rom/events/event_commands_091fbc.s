; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FBC
.include "src/rom/event_command_macros.inc"
event_0E6_command_1FBC:
    event_call 252
event_0E6_command_1FBE:
    event_world_transition 49
event_0E6_command_1FC0:
    event_call 247
event_0E6_command_1FC2:
    event_jump 1567
event_0E6_command_1FC4:
    event_end 
event_0E7_command_1FC5:
    event_object_command_37 50
