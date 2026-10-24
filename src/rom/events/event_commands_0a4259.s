; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4259
.include "src/rom/event_command_macros.inc"
event_4E7_command_4259:
    event_end 
event_4E8_command_425A:
    event_set_flag 10, 1
event_4E8_command_425D:
    event_refresh_objects 
