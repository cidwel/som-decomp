; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BEB2
.include "src/rom/event_command_macros.inc"
event_2CF_command_BEB2:
    event_jump 1535
event_2CF_command_BEB4:
    event_end 
event_2D0_command_BEB5:
    event_call 1988
event_2D0_command_BEB7:
    event_change_map 870
event_2D0_command_BEB9:
    event_end 
event_2D1_command_BEBA:
    event_test_actor_field 2, 4, 128, 233
event_2D1_command_BEBE:
    event_jump 719
event_2D1_command_BEC0:
    event_call 1864
