; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1DBE
.include "src/rom/event_command_macros.inc"
event_0DC_command_1DBE:
    event_jump 79
event_0DC_command_1DC0:
    event_jump 818
event_0DC_command_1DC2:
    event_jump 79
event_0DC_command_1DC4:
    event_end 
event_0DD_command_1DC5:
    event_end 
event_0DE_command_1DC6:
    event_end 
event_0DF_command_1DC7:
    event_set_flag 15, 0
event_0DF_command_1DCA:
    event_call 1032
