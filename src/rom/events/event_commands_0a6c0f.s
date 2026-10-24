; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C0F
.include "src/rom/event_command_macros.inc"
event_581_command_6C0F:
    event_call 1051
event_581_command_6C11:
    event_restore_hero 132
event_581_command_6C13:
    event_freeze 
event_581_command_6C14:
    event_wait 0
