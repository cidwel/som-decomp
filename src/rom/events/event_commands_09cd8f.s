; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CD8F
.include "src/rom/event_command_macros.inc"
event_318_command_CD8F:
    event_freeze 
event_318_command_CD90:
    event_gather 
event_318_command_CD91:
    event_screen 8
