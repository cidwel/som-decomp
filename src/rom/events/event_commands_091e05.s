; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E05
.include "src/rom/event_command_macros.inc"
event_0DF_command_1E05:
    event_jump 255
event_0DF_command_1E07:
    event_jump 244
event_0DF_command_1E09:
    event_jump 245
event_0DF_command_1E0B:
    event_end 
event_0E0_command_1E0C:
    event_set_flag 15, 0
event_0E0_command_1E0F:
    event_call 1032
