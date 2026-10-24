; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $46A1
.include "src/rom/event_command_macros.inc"
event_4E8_command_46A1:
    event_set_flag 10, 0
event_4E8_command_46A4:
    event_refresh_objects 
event_4E8_command_46A5:
    event_set_flag 46, 1
event_4E8_command_46A8:
    event_jump 1535
event_4E8_command_46AA:
    event_end 
