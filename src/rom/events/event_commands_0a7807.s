; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7807
.include "src/rom/event_command_macros.inc"
event_5B0_command_7807:
    event_jump 1457
event_5B0_command_7809:
    event_jump 1457
event_5B0_command_780B:
    event_jump 1457
event_5B0_command_780D:
    event_jump 1459
event_5B0_command_780F:
    event_jump 1460
event_5B0_command_7811:
    event_jump 1457
event_5B0_command_7813:
    event_jump 1458
event_5B0_command_7815:
    event_jump 1457
event_5B0_command_7817:
    event_jump 1457
event_5B0_command_7819:
    event_end 
event_5B1_command_781A:
    event_set_flag 90, 0
