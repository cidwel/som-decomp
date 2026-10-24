; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $14E2
.include "src/rom/event_command_macros.inc"
event_084_command_14E2:
    event_decrement_flag 255
event_084_command_14E4:
    event_jump 1796
event_084_command_14E6:
    event_end 
event_085_command_14E7:
    event_end 
event_086_command_14E8:
    event_end 
event_087_command_14E9:
    event_end 
event_088_command_14EA:
    event_end 
event_089_command_14EB:
    event_end 
event_08A_command_14EC:
    event_end 
event_08B_command_14ED:
    event_end 
event_08C_command_14EE:
    event_end 
event_08D_command_14EF:
    event_end 
event_08E_command_14F0:
    event_end 
event_08F_command_14F1:
    event_end 
event_090_command_14F2:
    event_end 
event_091_command_14F3:
    event_end 
event_092_command_14F4:
    event_end 
event_093_command_14F5:
    event_end 
event_094_command_14F6:
    event_end 
event_095_command_14F7:
    event_end 
event_096_command_14F8:
    event_end 
event_097_command_14F9:
    event_end 
event_098_command_14FA:
    event_end 
event_099_command_14FB:
    event_call 1152
