; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1AAD
.include "src/rom/event_command_macros.inc"
event_4A3_command_1AAD:
    event_decrement_flag 255
event_4A3_command_1AAF:
    event_end 
event_4A4_command_1AB0:
    event_increment_flag 68
event_4A4_command_1AB2:
    event_increment_flag 255
event_4A4_command_1AB4:
    event_call 1283
event_4A4_command_1AB6:
    event_call 1925
event_4A4_command_1AB8:
    event_screen 2
event_4A4_command_1ABA:
    event_wait 8
event_4A4_command_1ABC:
    event_call 1152
