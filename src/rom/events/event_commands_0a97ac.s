; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $97AC
.include "src/rom/event_command_macros.inc"
event_7FB_command_97AC:
    event_return 
event_7FB_command_97AD:
    event_end 
event_7FC_command_97AE:
    event_end 
event_7FD_command_97AF:
    event_increment_flag 255
