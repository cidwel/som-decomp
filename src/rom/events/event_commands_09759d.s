; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $759D
.include "src/rom/event_command_macros.inc"
event_1CC_command_759D:
    event_jump 461
event_1CC_command_759F:
    event_jump 462
event_1CC_command_75A1:
    event_jump 461
event_1CC_command_75A3:
    event_end 
event_1CD_command_75A4:
    event_call 95
