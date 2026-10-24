; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $97FB
.include "src/rom/event_command_macros.inc"
event_226_command_97FB:
    event_jump 1535
event_226_command_97FD:
    event_end 
