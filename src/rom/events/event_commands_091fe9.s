; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FE9
.include "src/rom/event_command_macros.inc"
event_0E7_command_1FE9:
    event_call 252
event_0E7_command_1FEB:
    event_world_transition 46
event_0E7_command_1FED:
    event_call 247
event_0E7_command_1FEF:
    event_jump 1564
event_0E7_command_1FF1:
    event_end 
event_0E8_command_1FF2:
    event_object_command_37 50
