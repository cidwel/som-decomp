; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $182E
.include "src/rom/event_command_macros.inc"
event_0B5_command_182E:
    event_jump 1535
event_0B5_command_1830:
    event_end 
