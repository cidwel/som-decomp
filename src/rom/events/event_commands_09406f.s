; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $406F
.include "src/rom/event_command_macros.inc"
event_13A_command_406F:
    event_hero_command 155
event_13A_command_4071:
    event_increment_flag 195
