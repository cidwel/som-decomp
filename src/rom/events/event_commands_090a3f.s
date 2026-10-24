; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0A3F
.include "src/rom/event_command_macros.inc"
event_021_command_0A3F:
    event_jump 1535
event_021_command_0A41:
    event_end 
event_022_command_0A42:
    event_call 31
