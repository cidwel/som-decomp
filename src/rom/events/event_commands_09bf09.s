; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BF09
.include "src/rom/event_command_macros.inc"
event_2D1_command_BF09:
    event_increment_flag 60
event_2D1_command_BF0B:
    event_change_map 871
event_2D1_command_BF0D:
    event_jump 1829
event_2D1_command_BF0F:
    event_end 
event_2D2_command_BF10:
    event_call 1151
