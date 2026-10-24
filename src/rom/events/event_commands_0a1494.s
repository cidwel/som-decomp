; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1494
.include "src/rom/event_command_macros.inc"
event_42D_command_1494:
    event_decrement_flag 255
event_42D_command_1496:
    event_call 1841
event_42D_command_1498:
    event_change_map 47
event_42D_command_149A:
    event_call 1152
event_42D_command_149C:
    event_wait 32
event_42D_command_149E:
    event_call 1924
event_42D_command_14A0:
    event_screen 2
event_42D_command_14A2:
    event_wait 8
event_42D_command_14A4:
    event_screen 8
event_42D_command_14A6:
    event_call 1846
