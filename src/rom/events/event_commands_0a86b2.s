; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $86B2
.include "src/rom/event_command_macros.inc"
event_609_command_86B2:
    event_jump 1535
event_609_command_86B4:
    event_end 
