; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9F2E
.include "src/rom/event_command_macros.inc"
event_24B_command_9F2E:
    event_jump 1535
event_24B_command_9F30:
    event_end 
event_24C_command_9F31:
    event_test_actor_field 2, 4, 128, 233
event_24C_command_9F35:
    event_jump 590
event_24C_command_9F37:
    event_test_actor_field 2, 5, 128, 233
event_24C_command_9F3B:
    event_jump 590
event_24C_command_9F3D:
    event_test_actor_field 2, 6, 128, 233
event_24C_command_9F41:
    event_jump 590
