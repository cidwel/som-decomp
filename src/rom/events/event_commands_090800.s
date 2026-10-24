; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0800
.include "src/rom/event_command_macros.inc"
event_000_command_0800:
    event_end 
event_001_command_0801:
    event_test_actor_field 3, 0, 145, 18
event_001_command_0805:
    event_jump 0
event_001_command_0807:
    event_test_actor_field 6, 0, 227, 251
event_001_command_080B:
    event_call 9
event_001_command_080D:
    event_test_actor_field 1, 128, 129, 1
event_001_command_0811:
    event_jump 0
event_001_command_0813:
    event_test_actor 0
event_001_command_0815:
    event_call 3
event_001_command_0817:
    event_test_actor 1
event_001_command_0819:
    event_call 4
event_001_command_081B:
    event_test_actor 2
event_001_command_081D:
    event_call 5
event_001_command_081F:
    event_set_actor_field 128, 129, 255
event_001_command_0823:
    event_party_command 12
event_001_command_0825:
    event_call 2
event_001_command_0827:
    event_end 
event_002_command_0828:
    event_test_actor_field 3, 0, 145, 18
event_002_command_082C:
    event_jump 0
event_002_command_082E:
    event_test_actor_field 6, 0, 227, 251
event_002_command_0832:
    event_party_command 8
event_002_command_0834:
    event_test_actor_field 6, 0, 227, 251
event_002_command_0838:
    event_restore_hero 64
event_002_command_083A:
    event_actor_animation 128, 129
event_002_command_083D:
    event_wait_idle 
event_002_command_083E:
    event_actor_animation 128, 131
event_002_command_0841:
    event_actor_animation 0, 155
event_002_command_0844:
    event_wait_idle 
event_002_command_0845:
    event_actor_walk 128, 0, 0
event_002_command_0848:
    event_actor_animation_loop 0, 128
event_002_command_084B:
    event_wait_idle 
event_002_command_084C:
    event_actor_animation_loop 128, 130
event_002_command_084F:
    event_wait_idle 
event_002_command_0850:
    event_return 
event_002_command_0851:
    event_end 
event_003_command_0852:
    event_set_actor_field 128, 172, 0
event_003_command_0856:
    event_return 
event_003_command_0857:
    event_end 
event_004_command_0858:
    event_set_actor_field 128, 172, 1
event_004_command_085C:
    event_return 
event_004_command_085D:
    event_end 
event_005_command_085E:
    event_set_actor_field 128, 172, 2
event_005_command_0862:
    event_return 
event_005_command_0863:
    event_end 
event_006_command_0864:
    event_actor_animation_loop 0, 128
event_006_command_0867:
    event_end 
event_007_command_0868:
    event_actor_animation_loop 0, 128
event_007_command_086B:
    event_set_actor_field 0, 155, 0
event_007_command_086F:
    event_return 
event_007_command_0870:
    event_end 
event_008_command_0871:
    event_test_flag_range 127, 1, 15
event_008_command_0874:
    event_jump 10
event_008_command_0876:
    event_increment_flag 127
event_008_command_0878:
    event_increment_flag 255
event_008_command_087A:
    event_call 1864
event_008_command_087C:
    event_call 1189
event_008_command_087E:
    event_screen_word 6, 17407
event_008_command_0882:
    event_wait 32
event_008_command_0884:
    event_call 1922
event_008_command_0886:
    event_screen 7
event_008_command_0888:
    event_wait 32
event_008_command_088A:
    event_call 11
event_008_command_088C:
    event_call 1865
event_008_command_088E:
    event_decrement_flag 255
event_008_command_0890:
    event_end 
event_009_command_0891:
    event_party_command 8
event_009_command_0893:
    event_restore_hero 68
event_009_command_0895:
    event_return 
event_009_command_0896:
    event_end 
event_00A_command_0897:
    event_call 11
event_00A_command_0899:
    event_end 
