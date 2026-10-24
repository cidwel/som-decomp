; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E0C
.include "src/rom/event_command_macros.inc"
event_581_command_6E0C:
    event_call 2004
event_581_command_6E0E:
    event_increment_flag 199
event_581_command_6E10:
    event_hero_command 191
event_581_command_6E12:
    event_party_command 8
event_581_command_6E14:
    event_restore_hero 68
event_581_command_6E16:
    event_wait 0
