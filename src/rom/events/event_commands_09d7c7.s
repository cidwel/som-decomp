; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D7C7
.include "src/rom/event_command_macros.inc"
event_376_command_D7C7:
    event_jump 1535
event_376_command_D7C9:
    event_end 
event_377_command_D7CA:
    event_end 
event_378_command_D7CB:
    event_call 1152
