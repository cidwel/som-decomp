; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $89AE
.include "src/rom/event_command_macros.inc"
event_65F_command_89AE:
    event_jump 0
event_65F_command_89B0:
    event_jump 80
event_65F_command_89B2:
    event_jump 776
event_65F_command_89B4:
    event_jump 789
event_65F_command_89B6:
    event_end 
event_660_command_89B7:
    event_test_flag_range 85, 1, 15
event_660_command_89BA:
    event_jump 0
event_660_command_89BC:
    event_call 1932
event_660_command_89BE:
    event_set_flag 85, 1
event_660_command_89C1:
    event_redraw_pieces 
event_660_command_89C2:
    event_end 
event_661_command_89C3:
    event_test_flag_range 85, 0, 0
event_661_command_89C6:
    event_jump 0
event_661_command_89C8:
    event_test_flag_range 85, 2, 15
event_661_command_89CB:
    event_jump 0
event_661_command_89CD:
    event_freeze 
event_661_command_89CE:
    event_gather 
event_661_command_89CF:
    event_call 1932
event_661_command_89D1:
    event_set_flag 85, 0
event_661_command_89D4:
    event_redraw_pieces 
event_661_command_89D5:
    event_end 
event_662_command_89D6:
    event_call 1937
event_662_command_89D8:
    event_call 1945
event_662_command_89DA:
    event_end 
event_663_command_89DB:
    event_test_flag_range 85, 2, 15
event_663_command_89DE:
    event_jump 0
event_663_command_89E0:
    event_call 1937
event_663_command_89E2:
    event_call 1944
event_663_command_89E4:
    event_set_flag 85, 2
event_663_command_89E7:
    event_redraw_pieces 
event_663_command_89E8:
    event_end 
event_664_command_89E9:
    event_test_flag_range 85, 3, 15
event_664_command_89EC:
    event_jump 0
event_664_command_89EE:
    event_call 1937
event_664_command_89F0:
    event_call 1944
event_664_command_89F2:
    event_set_flag 85, 3
event_664_command_89F5:
    event_redraw_pieces 
event_664_command_89F6:
    event_end 
event_665_command_89F7:
    event_test_flag_range 86, 1, 15
event_665_command_89FA:
    event_jump 0
event_665_command_89FC:
    event_call 1937
event_665_command_89FE:
    event_call 1944
event_665_command_8A00:
    event_set_flag 86, 1
event_665_command_8A03:
    event_redraw_pieces 
event_665_command_8A04:
    event_end 
event_666_command_8A05:
    event_call 1945
event_666_command_8A07:
    event_end 
event_667_command_8A08:
    event_test_flag_range 86, 2, 15
event_667_command_8A0B:
    event_jump 0
event_667_command_8A0D:
    event_call 1937
event_667_command_8A0F:
    event_call 1944
event_667_command_8A11:
    event_set_flag 86, 2
event_667_command_8A14:
    event_redraw_pieces 
event_667_command_8A15:
    event_end 
event_668_command_8A16:
    event_test_flag_range 86, 3, 15
event_668_command_8A19:
    event_jump 0
event_668_command_8A1B:
    event_freeze 
event_668_command_8A1C:
    event_actor_walk 0, 0, 32
event_668_command_8A1F:
    event_wait_idle 
event_668_command_8A20:
    event_gather 
event_668_command_8A21:
    event_call 1923
event_668_command_8A23:
    event_set_flag 86, 3
event_668_command_8A26:
    event_redraw_pieces 
event_668_command_8A27:
    event_end 
event_669_command_8A28:
    event_freeze 
event_669_command_8A29:
    event_gather 
event_669_command_8A2A:
    event_test_flag_range 86, 4, 15
event_669_command_8A2D:
    event_jump 0
event_669_command_8A2F:
    event_call 1040
event_669_command_8A31:
    event_set_flag 38, 2
event_669_command_8A34:
    event_call 1937
event_669_command_8A36:
    event_call 1944
event_669_command_8A38:
    event_set_flag 86, 4
event_669_command_8A3B:
    event_redraw_pieces 
event_669_command_8A3C:
    event_actor_animation 1, 174
event_669_command_8A3F:
    event_actor_animation 2, 174
event_669_command_8A42:
    event_actor_animation 3, 174
event_669_command_8A45:
    event_wait_idle 
event_669_command_8A46:
    event_toggle_visibility_04 
event_669_command_8A47:
    event_set_flag 37, 0
event_669_command_8A4A:
    event_change_map 706
event_669_command_8A4C:
    event_call 247
event_669_command_8A4E:
    event_jump 1796
event_669_command_8A50:
    event_end 
event_66A_command_8A51:
    event_increment_flag 37
event_66A_command_8A53:
    event_test_flag_range 37, 0, 2
event_66A_command_8A56:
    event_jump 0
event_66A_command_8A58:
    event_set_flag 86, 5
event_66A_command_8A5B:
    event_set_flag 38, 3
event_66A_command_8A5E:
    event_change_map 707
event_66A_command_8A60:
    event_jump 1813
event_66A_command_8A62:
    event_end 
event_66B_command_8A63:
    event_test_flag_range 38, 4, 15
event_66B_command_8A66:
    event_jump 0
event_66B_command_8A68:
    event_call 1152
event_66B_command_8A6A:
    event_actor_walk 1, 0, 60
event_66B_command_8A6D:
    event_actor_walk 2, 0, 60
event_66B_command_8A70:
    event_actor_walk 3, 0, 60
event_66B_command_8A73:
    event_wait_idle 
event_66B_command_8A74:
    event_screen 8
event_66B_command_8A76:
    event_increment_flag 248
