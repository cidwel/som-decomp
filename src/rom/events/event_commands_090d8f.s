; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0D8F
.include "src/rom/event_command_macros.inc"
event_02D_command_0D8F:
    event_jump 1535
event_02D_command_0D91:
    event_end 
event_02E_command_0D92:
    event_end 
