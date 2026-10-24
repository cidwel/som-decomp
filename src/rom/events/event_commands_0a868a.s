; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $868A
.include "src/rom/event_command_macros.inc"
event_608_command_868A:
    event_jump 1535
event_608_command_868C:
    event_end 
