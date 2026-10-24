; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $791F
.include "src/rom/event_command_macros.inc"
event_1D0_command_791F:
    event_increment_flag 21
event_1D0_command_7921:
    event_change_map 86
event_1D0_command_7923:
    event_jump 1823
event_1D0_command_7925:
    event_end 
event_1D1_command_7926:
    event_object_command_36 50
