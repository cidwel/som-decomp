; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E327
.include "src/rom/event_command_macros.inc"
event_3AA_command_E327:
    event_increment_flag 50
event_3AA_command_E329:
    event_refresh_objects 
event_3AA_command_E32A:
    event_end 
event_3AB_command_E32B:
    event_end 
