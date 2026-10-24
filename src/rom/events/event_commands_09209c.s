; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $209C
.include "src/rom/event_command_macros.inc"
event_0EA_command_209C:
    event_call 252
event_0EA_command_209E:
    event_world_transition 44
event_0EA_command_20A0:
    event_call 247
event_0EA_command_20A2:
    event_jump 1564
event_0EA_command_20A4:
    event_end 
event_0EB_command_20A5:
    event_test_flag_range 40, 0, 0
event_0EB_command_20A8:
    event_jump 229
event_0EB_command_20AA:
    event_object_command_37 50
