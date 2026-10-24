; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BC7F
.include "src/rom/event_command_macros.inc"
event_2C0_command_BC7F:
    event_jump 1535
event_2C0_command_BC81:
    event_end 
event_2C1_command_BC82:
    event_test_flag_range 148, 0, 0
event_2C1_command_BC85:
    event_jump 704
event_2C1_command_BC87:
    event_change_map 576
event_2C1_command_BC89:
    event_call 1152
event_2C1_command_BC8B:
    event_call 1933
event_2C1_command_BC8D:
    event_call 1952
event_2C1_command_BC8F:
    event_actor_walk 4, 1, 0
event_2C1_command_BC92:
    event_wait_idle 
event_2C1_command_BC93:
    event_wait 16
