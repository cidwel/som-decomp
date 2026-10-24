; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $96C8
.include "src/rom/event_command_macros.inc"
event_21F_command_96C8:
    event_jump 1535
event_21F_command_96CA:
    event_end 
