; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $19B0
.include "src/rom/event_command_macros.inc"
event_4A1_command_19B0:
    event_increment_flag 68
event_4A1_command_19B2:
    event_change_map 991
event_4A1_command_19B4:
    event_call 1988
event_4A1_command_19B6:
    event_end 
event_4A2_command_19B7:
    event_call 1284
event_4A2_command_19B9:
    event_increment_flag 255
event_4A2_command_19BB:
    event_increment_flag 248
