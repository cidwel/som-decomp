; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6A34
.include "src/rom/event_command_macros.inc"
event_1B6_command_6A34:
    event_test_flag_range 15, 1, 15
event_1B6_command_6A37:
    event_jump 823
event_1B6_command_6A39:
    event_call 1943
event_1B6_command_6A3B:
    event_hero_command 146
event_1B6_command_6A3D:
    event_party_command 8
event_1B6_command_6A3F:
    event_restore_hero 68
event_1B6_command_6A41:
    event_increment_flag 194
