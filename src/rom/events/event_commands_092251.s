; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2251
.include "src/rom/event_command_macros.inc"
event_0F2_command_2251:
    event_call 252
event_0F2_command_2253:
    event_world_transition 50
event_0F2_command_2255:
    event_call 247
event_0F2_command_2257:
    event_jump 1567
event_0F2_command_2259:
    event_end 
event_0F3_command_225A:
    event_object_command_37 50
