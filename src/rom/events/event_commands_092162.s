; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2162
.include "src/rom/event_command_macros.inc"
event_0ED_command_2162:
    event_call 252
event_0ED_command_2164:
    event_world_transition 37
event_0ED_command_2166:
    event_call 247
event_0ED_command_2168:
    event_jump 1565
event_0ED_command_216A:
    event_end 
event_0EE_command_216B:
    event_object_command_37 50
