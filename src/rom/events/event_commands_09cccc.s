; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CCCC
.include "src/rom/event_command_macros.inc"
event_311_command_CCCC:
    event_end 
event_312_command_CCCD:
    event_test_flag_range 250, 0, 0
event_312_command_CCD0:
    event_actor_effect 0
event_312_command_CCD2:
    event_test_flag_range 250, 1, 1
event_312_command_CCD5:
    event_actor_effect 1
event_312_command_CCD7:
    event_test_flag_range 250, 2, 2
event_312_command_CCDA:
    event_actor_effect 2
event_312_command_CCDC:
    event_test_flag_range 250, 3, 3
event_312_command_CCDF:
    event_actor_effect 3
event_312_command_CCE1:
    event_test_flag_range 250, 4, 4
event_312_command_CCE4:
    event_actor_effect 4
event_312_command_CCE6:
    event_test_flag_range 250, 5, 5
event_312_command_CCE9:
    event_actor_effect 5
event_312_command_CCEB:
    event_test_flag_range 250, 6, 6
event_312_command_CCEE:
    event_actor_effect 6
event_312_command_CCF0:
    event_test_flag_range 250, 7, 7
event_312_command_CCF3:
    event_actor_effect 7
event_312_command_CCF5:
    event_test_flag_range 250, 8, 8
event_312_command_CCF8:
    event_actor_effect 8
event_312_command_CCFA:
    event_test_flag_range 250, 9, 9
event_312_command_CCFD:
    event_actor_effect 9
event_312_command_CCFF:
    event_test_flag_range 250, 10, 10
event_312_command_CD02:
    event_actor_effect 10
event_312_command_CD04:
    event_test_flag_range 250, 11, 11
event_312_command_CD07:
    event_actor_effect 11
event_312_command_CD09:
    event_test_flag_range 250, 12, 12
event_312_command_CD0C:
    event_actor_effect 12
event_312_command_CD0E:
    event_test_flag_range 250, 13, 13
event_312_command_CD11:
    event_actor_effect 13
event_312_command_CD13:
    event_test_flag_range 250, 14, 14
event_312_command_CD16:
    event_actor_effect 14
event_312_command_CD18:
    event_test_flag_range 250, 15, 15
event_312_command_CD1B:
    event_actor_effect 15
event_312_command_CD1D:
    event_jump 788
event_312_command_CD1F:
    event_end 
event_313_command_CD20:
    event_actor_effect_0e 
event_313_command_CD21:
    event_jump 788
event_313_command_CD23:
    event_end 
