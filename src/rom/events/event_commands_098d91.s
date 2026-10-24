; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8D91
.include "src/rom/event_command_macros.inc"
event_201_command_8D91:
    event_end 
event_201_command_8D92:
    event_end 
event_201_command_8D93:
    event_jump 514
event_201_command_8D95:
    event_increment_flag 10
event_201_command_8D97:
    event_jump 515
event_201_command_8D99:
    event_end 
