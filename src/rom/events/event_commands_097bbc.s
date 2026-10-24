; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7BBC
.include "src/rom/event_command_macros.inc"
event_1D4_command_7BBC:
    event_hero_command 173
event_1D4_command_7BBE:
    event_party_command 8
event_1D4_command_7BC0:
    event_restore_hero 68
event_1D4_command_7BC2:
    event_increment_flag 197
