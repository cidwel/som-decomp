; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ABD5
.include "src/rom/event_command_macros.inc"
event_28B_command_ABD5:
    event_call 1864
event_28B_command_ABD7:
    event_screen_word 6, 65535
event_28B_command_ABDB:
    event_wait 32
event_28B_command_ABDD:
    event_call 1054
event_28B_command_ABDF:
    event_set_flag 13, 8
event_28B_command_ABE2:
    event_delete_actor 1
event_28B_command_ABE4:
    event_set_flag 14, 8
event_28B_command_ABE7:
    event_delete_actor 2
event_28B_command_ABE9:
    event_change_map 426
event_28B_command_ABEB:
    event_call 1865
event_28B_command_ABED:
    event_jump 653
event_28B_command_ABEF:
    event_end 
event_28C_command_ABF0:
    event_test_flag_range 40, 1, 10
event_28C_command_ABF3:
    event_jump 683
event_28C_command_ABF5:
    event_test_flag_range 40, 11, 15
event_28C_command_ABF8:
    event_jump 669
