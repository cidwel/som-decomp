; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $855F
.include "src/rom/event_command_macros.inc"
event_5F8_command_855F:
    event_jump 1529
event_5F8_command_8561:
    event_end 
event_5F9_command_8562:
    event_set_flag 144, 1
event_5F9_command_8565:
    event_set_flag 145, 1
event_5F9_command_8568:
    event_set_flag 146, 1
event_5F9_command_856B:
    event_set_flag 147, 1
event_5F9_command_856E:
    event_set_flag 148, 1
event_5F9_command_8571:
    event_set_flag 149, 1
event_5F9_command_8574:
    event_set_flag 150, 1
event_5F9_command_8577:
    event_set_flag 151, 1
event_5F9_command_857A:
    event_set_flag 192, 9
event_5F9_command_857D:
    event_set_flag 193, 8
event_5F9_command_8580:
    event_set_flag 194, 9
event_5F9_command_8583:
    event_set_flag 195, 9
event_5F9_command_8586:
    event_set_flag 196, 9
event_5F9_command_8589:
    event_set_flag 197, 9
event_5F9_command_858C:
    event_set_flag 198, 9
event_5F9_command_858F:
    event_set_flag 199, 9
event_5F9_command_8592:
    event_set_flag 252, 8
event_5F9_command_8595:
    event_end 
event_5FA_command_8596:
    event_end 
event_5FB_command_8597:
    event_end 
event_5FC_command_8598:
    event_end 
event_5FD_command_8599:
    event_end 
event_5FE_command_859A:
    event_wait 0
