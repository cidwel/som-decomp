; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $98B7
.include "src/rom/event_command_macros.inc"
event_228_command_98B7:
    event_jump 1535
event_228_command_98B9:
    event_end 
event_229_command_98BA:
    event_audio_request 2, 114, 15, 136
event_229_command_98BF:
    event_increment_flag 28
event_229_command_98C1:
    event_redraw_pieces 
event_229_command_98C2:
    event_return 
event_229_command_98C3:
    event_end 
event_22A_command_98C4:
    event_audio_request 2, 114, 15, 136
event_22A_command_98C9:
    event_increment_flag 29
event_22A_command_98CB:
    event_redraw_pieces 
event_22A_command_98CC:
    event_return 
event_22A_command_98CD:
    event_end 
event_22B_command_98CE:
    event_call 1937
event_22B_command_98D0:
    event_increment_flag 28
event_22B_command_98D2:
    event_increment_flag 29
event_22B_command_98D4:
    event_redraw_pieces 
event_22B_command_98D5:
    event_call 1932
event_22B_command_98D7:
    event_end 
event_22C_command_98D8:
    event_test_flag_range 28, 0, 0
event_22C_command_98DB:
    event_call 553
event_22C_command_98DD:
    event_test_flag_range 29, 1, 1
event_22C_command_98E0:
    event_jump 555
event_22C_command_98E2:
    event_end 
event_22D_command_98E3:
    event_test_flag_range 29, 0, 0
event_22D_command_98E6:
    event_call 554
event_22D_command_98E8:
    event_test_flag_range 28, 1, 1
event_22D_command_98EB:
    event_jump 555
event_22D_command_98ED:
    event_end 
event_22E_command_98EE:
    event_call 1150
event_22E_command_98F0:
    event_wait 16
