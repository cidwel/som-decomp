; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BCDA
.include "src/rom/event_command_macros.inc"
event_2C1_command_BCDA:
    event_jump 1535
event_2C1_command_BCDC:
    event_end 
event_2C2_command_BCDD:
    event_change_map 577
event_2C2_command_BCDF:
    event_call 1152
event_2C2_command_BCE1:
    event_call 1933
event_2C2_command_BCE3:
    event_call 1952
