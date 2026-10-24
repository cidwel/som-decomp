; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9DAC
.include "src/rom/event_command_macros.inc"
event_23C_command_9DAC:
    event_jump 255
event_23C_command_9DAE:
    event_jump 79
event_23C_command_9DB0:
    event_jump 774
event_23C_command_9DB2:
    event_jump 787
event_23C_command_9DB4:
    event_end 
event_23D_command_9DB5:
    event_test_flag_range 20, 15, 15
event_23D_command_9DB8:
    event_jump 574
