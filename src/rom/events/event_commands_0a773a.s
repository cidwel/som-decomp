; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $773A
.include "src/rom/event_command_macros.inc"
event_59D_command_773A:
    event_actor_animation 0, 140
event_59D_command_773D:
    event_wait_idle 
event_59D_command_773E:
    event_jump 1535
event_59D_command_7740:
    event_end 
event_59E_command_7741:
    event_test_flag_range 55, 0, 0
event_59E_command_7744:
    event_jump 1437
event_59E_command_7746:
    event_change_map 670
event_59E_command_7748:
    event_test_flag_range 55, 0, 4
event_59E_command_774B:
    event_jump 1834
event_59E_command_774D:
    event_jump 1821
event_59E_command_774F:
    event_end 
event_59F_command_7750:
    event_test_flag_range 55, 0, 0
event_59F_command_7753:
    event_jump 1437
event_59F_command_7755:
    event_change_map 671
event_59F_command_7757:
    event_test_flag_range 55, 0, 4
event_59F_command_775A:
    event_jump 1834
event_59F_command_775C:
    event_jump 1821
event_59F_command_775E:
    event_end 
event_5A0_command_775F:
    event_test_flag_range 55, 0, 3
event_5A0_command_7762:
    event_jump 1796
event_5A0_command_7764:
    event_end 
event_5A1_command_7765:
    event_test_flag_range 55, 0, 3
event_5A1_command_7768:
    event_jump 0
event_5A1_command_776A:
    event_change_map 664
event_5A1_command_776C:
    event_end 
event_5A2_command_776D:
    event_call 1286
event_5A2_command_776F:
    event_increment_flag 55
event_5A2_command_7771:
    event_change_map 292
event_5A2_command_7773:
    event_call 1152
event_5A2_command_7775:
    event_call 1446
event_5A2_command_7777:
    event_jump 1834
event_5A2_command_7779:
    event_end 
event_5A3_command_777A:
    event_test_flag_range 55, 0, 6
event_5A3_command_777D:
    event_jump 1796
event_5A3_command_777F:
    event_end 
event_5A4_command_7780:
    event_test_flag_range 55, 0, 6
event_5A4_command_7783:
    event_jump 0
event_5A4_command_7785:
    event_change_map 676
event_5A4_command_7787:
    event_end 
event_5A5_command_7788:
    event_call 1285
event_5A5_command_778A:
    event_increment_flag 55
event_5A5_command_778C:
    event_change_map 293
event_5A5_command_778E:
    event_call 1152
event_5A5_command_7790:
    event_call 1446
event_5A5_command_7792:
    event_jump 1803
event_5A5_command_7794:
    event_end 
event_5A6_command_7795:
    event_audio_request 2, 18, 0, 136
event_5A6_command_779A:
    event_redraw_pieces 
event_5A6_command_779B:
    event_increment_flag 55
event_5A6_command_779D:
    event_redraw_pieces 
event_5A6_command_779E:
    event_increment_flag 55
event_5A6_command_77A0:
    event_redraw_pieces 
event_5A6_command_77A1:
    event_audio_request 242, 0, 0, 0
event_5A6_command_77A6:
    event_audio_request 2, 21, 15, 136
event_5A6_command_77AB:
    event_return 
event_5A6_command_77AC:
    event_end 
event_5A7_command_77AD:
    event_call 1922
event_5A7_command_77AF:
    event_wait 16
event_5A7_command_77B1:
    event_screen 7
event_5A7_command_77B3:
    event_end 
event_5A8_command_77B4:
    event_screen_word 5, 30313
event_5A8_command_77B8:
    event_jump 1447
event_5A8_command_77BA:
    event_end 
event_5A9_command_77BB:
    event_screen_word 5, 31
event_5A9_command_77BF:
    event_jump 1447
event_5A9_command_77C1:
    event_end 
event_5AA_command_77C2:
    event_screen_word 5, 30418
event_5AA_command_77C6:
    event_jump 1447
event_5AA_command_77C8:
    event_end 
event_5AB_command_77C9:
    event_screen_word 5, 4535
event_5AB_command_77CD:
    event_jump 1447
event_5AB_command_77CF:
    event_end 
event_5AC_command_77D0:
    event_screen_word 5, 32767
event_5AC_command_77D4:
    event_jump 1447
event_5AC_command_77D6:
    event_end 
event_5AD_command_77D7:
    event_screen_word 5, 6342
event_5AD_command_77DB:
    event_jump 1447
event_5AD_command_77DD:
    event_end 
event_5AE_command_77DE:
    event_screen_word 5, 1023
event_5AE_command_77E2:
    event_jump 1447
event_5AE_command_77E4:
    event_end 
event_5AF_command_77E5:
    event_screen_word 5, 992
event_5AF_command_77E9:
    event_jump 1447
event_5AF_command_77EB:
    event_end 
