; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6A26
.include "src/rom/event_command_macros.inc"
event_1B5_command_6A26:
    event_jump 433
event_1B5_command_6A28:
    event_jump 438
event_1B5_command_6A2A:
    event_jump 433
event_1B5_command_6A2C:
    event_end 
event_1B6_command_6A2D:
    event_set_flag 15, 0
event_1B6_command_6A30:
    event_object_command_37 100
