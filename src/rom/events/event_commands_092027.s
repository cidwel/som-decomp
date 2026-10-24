; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2027
.include "src/rom/event_command_macros.inc"
event_0E8_command_2027:
    event_call 252
event_0E8_command_2029:
    event_world_transition 47
event_0E8_command_202B:
    event_call 247
event_0E8_command_202D:
    event_jump 1565
event_0E8_command_202F:
    event_end 
event_0E9_command_2030:
    event_object_command_37 50
