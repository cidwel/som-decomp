; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $11E4
.include "src/rom/event_command_macros.inc"
event_063_command_11E4:
    event_jump 1535
event_063_command_11E6:
    event_end 
event_064_command_11E7:
    event_set_flag 253, 0
event_064_command_11EA:
    event_set_flag 254, 1
event_064_command_11ED:
    event_set_flag 249, 3
