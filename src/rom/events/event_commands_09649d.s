; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $649D
.include "src/rom/event_command_macros.inc"
event_1A6_command_649D:
    event_jump 1535
event_1A6_command_649F:
    event_end 
