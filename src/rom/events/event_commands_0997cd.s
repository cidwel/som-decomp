; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $97CD
.include "src/rom/event_command_macros.inc"
event_225_command_97CD:
    event_jump 1535
event_225_command_97CF:
    event_end 
