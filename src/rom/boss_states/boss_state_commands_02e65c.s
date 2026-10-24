.setcpu "65816"
.segment "CODE"
.org $E65C
.include "boss_state_command_macros.inc"
boss_state_pc_c2e65c:
    boss_state_anim $00CE
boss_state_pc_c2e65f:
    boss_state_frames $0000, $0000, $0000, $0001, $0000, $0008
boss_state_pc_c2e66c:
    boss_state_jump $E692
boss_state_pc_c2e66f:
    boss_state_anim $00D0
boss_state_pc_c2e672:
    boss_state_frames $0000, $FFFF, $0000, $0000, $0000, $0008
boss_state_pc_c2e67f:
    boss_state_jump $E692
boss_state_pc_c2e682:
    boss_state_anim $00CF
boss_state_pc_c2e685:
    boss_state_frames $0000, $0001, $0000, $0000, $0000, $0008
boss_state_pc_c2e692:
    boss_state_store $007C, $0001
boss_state_pc_c2e697:
    boss_state_store $0066, $0001
boss_state_pc_c2e69c:
    boss_state_speed90 $36BC
boss_state_pc_c2e69f:
    boss_state_f4a $3766
boss_state_pc_c2e6a2:
    boss_state_end
boss_state_pc_c2e6a3:
    boss_state_anim $00D1
boss_state_pc_c2e6a6:
    boss_state_store $007C, $0000
boss_state_pc_c2e6ab:
    boss_state_duration14 $0002
boss_state_pc_c2e6ae:
    boss_state_end
boss_state_pc_c2e6af:
    boss_state_clr98_40
boss_state_pc_c2e6b0:
    boss_state_anim $00D2
boss_state_pc_c2e6b3:
    boss_state_store $007E, $0001
boss_state_pc_c2e6b8:
    boss_state_store $007C, $0001
boss_state_pc_c2e6bd:
    boss_state_store $0082, $0000
boss_state_pc_c2e6c2:
    boss_state_store $0070, $0000
boss_state_pc_c2e6c7:
    boss_state_store $0066, $0001
boss_state_pc_c2e6cc:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0001
boss_state_pc_c2e6d9:
    boss_state_speed90 $6CCB
boss_state_pc_c2e6dc:
    boss_state_f4a $6CD9
boss_state_pc_c2e6df:
    boss_state_end
boss_state_pc_c2e6e0:
    boss_state_anim $00D4
boss_state_pc_c2e6e3:
    boss_state_store $007C, $0001
boss_state_pc_c2e6e8:
    boss_state_store $0082, $0000
boss_state_pc_c2e6ed:
    boss_state_store $0070, $0001
boss_state_pc_c2e6f2:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0000
boss_state_pc_c2e6ff:
    boss_state_speed90 $36BC
boss_state_pc_c2e702:
    boss_state_end
boss_state_pc_c2e703:
    boss_state_anim $00D3
boss_state_pc_c2e706:
    boss_state_speed90 $6CE0
boss_state_pc_c2e709:
    boss_state_duration14 $0018
boss_state_pc_c2e70c:
    boss_state_end
boss_state_pc_c2e70d:
    boss_state_set98_40
boss_state_pc_c2e70e:
    boss_state_jump $E712
boss_state_pc_c2e711:
    boss_state_clr98_40
boss_state_pc_c2e712:
    boss_state_anim $00D6
boss_state_pc_c2e715:
    boss_state_c0_006c $004D
boss_state_pc_c2e718:
    boss_state_end
boss_state_pc_c2e719:
    boss_state_anim $00D7
boss_state_pc_c2e71c:
    boss_state_end
boss_state_pc_c2e71d:
    boss_state_anim $00D8
boss_state_pc_c2e720:
    boss_state_c0_006c $0051
boss_state_pc_c2e723:
    boss_state_callnative $6BFF
boss_state_pc_c2e726:
    boss_state_f48 $6C35
boss_state_pc_c2e729:
    boss_state_speed90 $6C35
boss_state_pc_c2e72c:
    boss_state_duration14 $0024
boss_state_pc_c2e72f:
    boss_state_end
boss_state_pc_c2e730:
    boss_state_clr98_40
boss_state_pc_c2e731:
    boss_state_anim $00DC
boss_state_pc_c2e734:
    boss_state_spell $0008
boss_state_pc_c2e737:
    boss_state_end
boss_state_pc_c2e738:
    boss_state_clr98_40
boss_state_pc_c2e739:
    boss_state_anim $00DD
boss_state_pc_c2e73c:
    boss_state_spell $0006
boss_state_pc_c2e73f:
    boss_state_end
boss_state_pc_c2e740:
    boss_state_clr98_40
boss_state_pc_c2e741:
    boss_state_anim $00DC
boss_state_pc_c2e744:
    boss_state_spell $0008
boss_state_pc_c2e747:
    boss_state_end
boss_state_pc_c2e748:
    boss_state_clr98_40
boss_state_pc_c2e749:
    boss_state_anim $00DE
boss_state_pc_c2e74c:
    boss_state_spell $0025
boss_state_pc_c2e74f:
    boss_state_end
boss_state_pc_c2e750:
    boss_state_clr98_40
boss_state_pc_c2e751:
    boss_state_anim $00DE
boss_state_pc_c2e754:
    boss_state_spell $0026
boss_state_pc_c2e757:
    boss_state_end
boss_state_pc_c2e758:
    boss_state_anim $00DF
boss_state_pc_c2e75b:
    boss_state_spawn $0013, $0000, $00D0
boss_state_pc_c2e75f:
    boss_state_c0_006c $0013
boss_state_pc_c2e762:
    boss_state_duration14 $0018
boss_state_pc_c2e765:
    boss_state_end
boss_state_pc_c2e766:
    boss_state_anim $00DF
boss_state_pc_c2e769:
    boss_state_spawn $0017, $0000, $00D0
boss_state_pc_c2e76d:
    boss_state_c0_006c $004B
boss_state_pc_c2e770:
    boss_state_duration14 $0018
boss_state_pc_c2e773:
    boss_state_end
boss_state_pc_c2e774:
    boss_state_anim $00D5
boss_state_pc_c2e777:
    boss_state_f4a $34B9
boss_state_pc_c2e77a:
    boss_state_end
boss_state_pc_c2e77b:
    boss_state_anim $00E1
boss_state_pc_c2e77e:
    boss_state_end
boss_state_pc_c2e77f:
    boss_state_anim $00E2
boss_state_pc_c2e782:
    boss_state_end
boss_state_pc_c2e783:
    boss_state_anim $00CE
boss_state_pc_c2e786:
    boss_state_store $007C, $0001
boss_state_pc_c2e78b:
    boss_state_frames $0000, $0000, $0000, $FFFF, $0000, $0008
boss_state_pc_c2e798:
    boss_state_store $0066, $0001
boss_state_pc_c2e79d:
    boss_state_speed90 $36BC
boss_state_pc_c2e7a0:
    boss_state_f4a $3766
boss_state_pc_c2e7a3:
    boss_state_end
boss_state_pc_c2e7a4:
    boss_state_callnative $6C77
boss_state_pc_c2e7a7:
    boss_state_callnative $3CAB
boss_state_pc_c2e7aa:
    boss_state_duration14 $0001
boss_state_pc_c2e7ad:
    boss_state_end
boss_state_pc_c2e7ae:
    boss_state_anim $00CF
boss_state_pc_c2e7b1:
    boss_state_store $007C, $0001
boss_state_pc_c2e7b6:
    boss_state_store $00A7, $0005
boss_state_pc_c2e7bb:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0014
boss_state_pc_c2e7c8:
    boss_state_store $0066, $0001
boss_state_pc_c2e7cd:
    boss_state_speed90 $36BC
boss_state_pc_c2e7d0:
    boss_state_duration14 $0006
boss_state_pc_c2e7d3:
    boss_state_end
boss_state_pc_c2e7d4:
    boss_state_store $0070, $0000
boss_state_pc_c2e7d9:
    boss_state_speed90 $6D2F
boss_state_pc_c2e7dc:
    boss_state_duration14 $000C
boss_state_pc_c2e7df:
    boss_state_end
boss_state_pc_c2e7e0:
    boss_state_anim $00DA
boss_state_pc_c2e7e3:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFE2
boss_state_pc_c2e7f0:
    boss_state_store $0070, $0001
boss_state_pc_c2e7f5:
    boss_state_c0_006c $004E
boss_state_pc_c2e7f8:
    boss_state_speed90 $36BC
boss_state_pc_c2e7fb:
    boss_state_f4a $3766
boss_state_pc_c2e7fe:
    boss_state_end
boss_state_pc_c2e7ff:
    boss_state_anim $00DB
boss_state_pc_c2e802:
    boss_state_store $00A7, $0003
boss_state_pc_c2e807:
    boss_state_end
boss_state_pc_c2e808:
    boss_state_store $007C, $0000
boss_state_pc_c2e80d:
    boss_state_duration14 $0001
boss_state_pc_c2e810:
    boss_state_end
boss_state_pc_c2e811:
    boss_state_store $007E, $0000
boss_state_pc_c2e816:
    boss_state_store $007C, $0000
boss_state_pc_c2e81b:
    boss_state_duration14 $0001
boss_state_pc_c2e81e:
    boss_state_end
boss_state_pc_c2e81f:
    boss_state_anim $00D4
boss_state_pc_c2e822:
    boss_state_end
boss_state_pc_c2e823:
    boss_state_anim $00D2
boss_state_pc_c2e826:
    boss_state_callnative $6BAE
boss_state_pc_c2e829:
    boss_state_c0_006c $0052
boss_state_pc_c2e82c:
    boss_state_end
boss_state_pc_c2e82d:
    boss_state_end
