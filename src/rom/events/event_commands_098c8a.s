; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8C8A
.include "src/rom/event_command_macros.inc"
event_1FE_command_8C8A:
    event_change_map 55
event_1FE_command_8C8C:
    event_jump 1797
event_1FE_command_8C8E:
    event_end 
event_1FF_command_8C8F:
    event_change_map 14
event_1FF_command_8C91:
    event_end 
