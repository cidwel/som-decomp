; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3CD3
.include "src/rom/event_command_macros.inc"
event_133_command_3CD3:
    event_end 
event_133_command_3CD4:
    event_end 
event_133_command_3CD5:
    event_jump 512
event_133_command_3CD7:
    event_jump 515
event_133_command_3CD9:
    event_end 
event_134_command_3CDA:
    event_test_flag_range 27, 1, 3
event_134_command_3CDD:
    event_jump 316
event_134_command_3CDF:
    event_set_flag 253, 0
event_134_command_3CE2:
    event_set_flag 254, 2
