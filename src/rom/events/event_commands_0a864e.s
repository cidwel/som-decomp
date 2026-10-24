; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $864E
.include "src/rom/event_command_macros.inc"
event_606_command_864E:
    event_jump 1535
event_606_command_8650:
    event_end 
