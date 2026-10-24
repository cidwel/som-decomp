; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CD47
.include "src/rom/event_command_macros.inc"
event_314_command_CD47:
    event_jump 785
event_314_command_CD49:
    event_jump 786
event_314_command_CD4B:
    event_jump 787
event_314_command_CD4D:
    event_end 
event_315_command_CD4E:
    event_call 1152
