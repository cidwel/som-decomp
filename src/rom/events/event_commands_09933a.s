; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $933A
.include "src/rom/event_command_macros.inc"
event_20F_command_933A:
    event_jump 527
event_20F_command_933C:
    event_jump 463
event_20F_command_933E:
    event_jump 527
event_20F_command_9340:
    event_end 
