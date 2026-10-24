.setcpu "65816"
.segment "CODE"
.org $E8F6
.include "boss_state_command_macros.inc"
boss_state_pc_c2e8f6:
    boss_state_anim $00E8
boss_state_pc_c2e8f9:
    boss_state_duration14 $0024
boss_state_pc_c2e8fc:
    boss_state_end
boss_state_pc_c2e8fd:
    boss_state_set98_40
boss_state_pc_c2e8fe:
    boss_state_anim $00E9
boss_state_pc_c2e901:
    boss_state_duration14 $0024
boss_state_pc_c2e904:
    boss_state_end
boss_state_pc_c2e905:
    boss_state_clr98_40
boss_state_pc_c2e906:
    boss_state_anim $00E9
boss_state_pc_c2e909:
    boss_state_duration14 $0024
boss_state_pc_c2e90c:
    boss_state_end
boss_state_pc_c2e90d:
    boss_state_anim $00E8
boss_state_pc_c2e910:
    boss_state_duration14 $0024
boss_state_pc_c2e913:
    boss_state_frames $0000, $0000, $0000, $0001, $0000, $0000
boss_state_pc_c2e920:
    boss_state_f48 $36BC
boss_state_pc_c2e923:
    boss_state_end
boss_state_pc_c2e924:
    boss_state_anim $00E8
boss_state_pc_c2e927:
    boss_state_duration14 $0024
boss_state_pc_c2e92a:
    boss_state_frames $0000, $0000, $0000, $FFFF, $0000, $0000
boss_state_pc_c2e937:
    boss_state_f48 $36BC
boss_state_pc_c2e93a:
    boss_state_end
boss_state_pc_c2e93b:
    boss_state_set98_40
boss_state_pc_c2e93c:
    boss_state_anim $00E9
boss_state_pc_c2e93f:
    boss_state_duration14 $0024
boss_state_pc_c2e942:
    boss_state_frames $0000, $FFFF, $0000, $0000, $0000, $0000
boss_state_pc_c2e94f:
    boss_state_f48 $36BC
boss_state_pc_c2e952:
    boss_state_end
boss_state_pc_c2e953:
    boss_state_clr98_40
boss_state_pc_c2e954:
    boss_state_anim $00E9
boss_state_pc_c2e957:
    boss_state_duration14 $0024
boss_state_pc_c2e95a:
    boss_state_frames $0000, $0001, $0000, $0000, $0000, $0000
boss_state_pc_c2e967:
    boss_state_f48 $36BC
boss_state_pc_c2e96a:
    boss_state_end
boss_state_pc_c2e96b:
    boss_state_anim $00EA
boss_state_pc_c2e96e:
    boss_state_f4a $34B9
boss_state_pc_c2e971:
    boss_state_end
boss_state_pc_c2e972:
    boss_state_anim $00EB
boss_state_pc_c2e975:
    boss_state_spell $0024
boss_state_pc_c2e978:
    boss_state_end
boss_state_pc_c2e979:
    boss_state_anim $00EC
boss_state_pc_c2e97c:
    boss_state_spell $0008
boss_state_pc_c2e97f:
    boss_state_end
boss_state_pc_c2e980:
    boss_state_anim $00ED
boss_state_pc_c2e983:
    boss_state_spell $0025
boss_state_pc_c2e986:
    boss_state_end
boss_state_pc_c2e987:
    boss_state_anim $00EE
boss_state_pc_c2e98a:
    boss_state_spell $0026
boss_state_pc_c2e98d:
    boss_state_end
boss_state_pc_c2e98e:
    boss_state_anim $00EF
boss_state_pc_c2e991:
    boss_state_spell $0013
boss_state_pc_c2e994:
    boss_state_end
boss_state_pc_c2e995:
    boss_state_anim $00F0
boss_state_pc_c2e998:
    boss_state_spell $0000
boss_state_pc_c2e99b:
    boss_state_end
boss_state_pc_c2e99c:
    boss_state_anim $00F1
boss_state_pc_c2e99f:
    boss_state_spell $0006
boss_state_pc_c2e9a2:
    boss_state_end
boss_state_pc_c2e9a3:
    boss_state_anim $00F3
boss_state_pc_c2e9a6:
    boss_state_spawn $0009, $0000, $00F0
boss_state_pc_c2e9aa:
    boss_state_duration14 $0024
boss_state_pc_c2e9ad:
    boss_state_c0_006c $0040
boss_state_pc_c2e9b0:
    boss_state_end
boss_state_pc_c2e9b1:
    boss_state_anim $00F3
boss_state_pc_c2e9b4:
    boss_state_spawn $0008, $0000, $00F0
boss_state_pc_c2e9b8:
    boss_state_duration14 $0024
boss_state_pc_c2e9bb:
    boss_state_c0_006c $003B
boss_state_pc_c2e9be:
    boss_state_end
boss_state_pc_c2e9bf:
    boss_state_anim $00F2
boss_state_pc_c2e9c2:
    boss_state_spawn $0017, $0000, $00E4
boss_state_pc_c2e9c6:
    boss_state_duration14 $0024
boss_state_pc_c2e9c9:
    boss_state_c0_006c $004C
boss_state_pc_c2e9cc:
    boss_state_end
boss_state_pc_c2e9cd:
    boss_state_anim $00F2
boss_state_pc_c2e9d0:
    boss_state_spawn $000F, $0000, $00E4
boss_state_pc_c2e9d4:
    boss_state_duration14 $0024
boss_state_pc_c2e9d7:
    boss_state_c0_006c $000F
boss_state_pc_c2e9da:
    boss_state_end
boss_state_pc_c2e9db:
    boss_state_anim $00F2
boss_state_pc_c2e9de:
    boss_state_spawn $0016, $0000, $00E4
boss_state_pc_c2e9e2:
    boss_state_duration14 $0024
boss_state_pc_c2e9e5:
    boss_state_c0_006c $004A
boss_state_pc_c2e9e8:
    boss_state_end
boss_state_pc_c2e9e9:
    boss_state_anim $00F2
boss_state_pc_c2e9ec:
    boss_state_spawn $0010, $0000, $00E4
boss_state_pc_c2e9f0:
    boss_state_duration14 $0024
boss_state_pc_c2e9f3:
    boss_state_c0_006c $0047
boss_state_pc_c2e9f6:
    boss_state_end
boss_state_pc_c2e9f7:
    boss_state_anim $00F2
boss_state_pc_c2e9fa:
    boss_state_spawn $0012, $0000, $00E4
boss_state_pc_c2e9fe:
    boss_state_duration14 $0024
boss_state_pc_c2ea01:
    boss_state_c0_006c $0049
boss_state_pc_c2ea04:
    boss_state_end
boss_state_pc_c2ea05:
    boss_state_anim $00F2
boss_state_pc_c2ea08:
    boss_state_spawn $000E, $0000, $00E4
boss_state_pc_c2ea0c:
    boss_state_duration14 $0024
boss_state_pc_c2ea0f:
    boss_state_c0_006c $000E
boss_state_pc_c2ea12:
    boss_state_end
boss_state_pc_c2ea13:
    boss_state_anim $00F2
boss_state_pc_c2ea16:
    boss_state_spawn $000F, $0000, $00E4
boss_state_pc_c2ea1a:
    boss_state_duration14 $0024
boss_state_pc_c2ea1d:
    boss_state_c0_006c $000F
boss_state_pc_c2ea20:
    boss_state_end
boss_state_pc_c2ea21:
    boss_state_anim $0000
boss_state_pc_c2ea24:
    boss_state_store $007C, $0001
boss_state_pc_c2ea29:
    boss_state_store $0082, $0000
boss_state_pc_c2ea2e:
    boss_state_callnative $6F05
boss_state_pc_c2ea31:
    boss_state_f48 $6ECB
boss_state_pc_c2ea34:
    boss_state_duration14 $0024
boss_state_pc_c2ea37:
    boss_state_end
boss_state_pc_c2ea38:
    boss_state_anim $0000
boss_state_pc_c2ea3b:
    boss_state_store $007C, $0001
boss_state_pc_c2ea40:
    boss_state_store $0082, $0000
boss_state_pc_c2ea45:
    boss_state_callnative $6F2E
boss_state_pc_c2ea48:
    boss_state_f48 $6ECB
boss_state_pc_c2ea4b:
    boss_state_duration14 $0024
boss_state_pc_c2ea4e:
    boss_state_end
boss_state_pc_c2ea4f:
    boss_state_store $007C, $0000
boss_state_pc_c2ea54:
    boss_state_store $0082, $0001
boss_state_pc_c2ea59:
    boss_state_store $007E, $0001
boss_state_pc_c2ea5e:
    boss_state_callnative $6EEB
boss_state_pc_c2ea61:
    boss_state_duration14 $0001
boss_state_pc_c2ea64:
    boss_state_end
boss_state_pc_c2ea65:
    boss_state_anim $0000
boss_state_pc_c2ea68:
    boss_state_store $007C, $0001
boss_state_pc_c2ea6d:
    boss_state_store $0082, $0000
boss_state_pc_c2ea72:
    boss_state_callnative $6F05
boss_state_pc_c2ea75:
    boss_state_f48 $6ECB
boss_state_pc_c2ea78:
    boss_state_duration14 $0024
boss_state_pc_c2ea7b:
    boss_state_end
boss_state_pc_c2ea7c:
    boss_state_anim $0000
boss_state_pc_c2ea7f:
    boss_state_store $007C, $0001
boss_state_pc_c2ea84:
    boss_state_store $0082, $0000
boss_state_pc_c2ea89:
    boss_state_callnative $6F68
boss_state_pc_c2ea8c:
    boss_state_f48 $6ECB
boss_state_pc_c2ea8f:
    boss_state_duration14 $0024
boss_state_pc_c2ea92:
    boss_state_end
boss_state_pc_c2ea93:
    boss_state_store $007C, $0000
boss_state_pc_c2ea98:
    boss_state_store $0082, $0001
boss_state_pc_c2ea9d:
    boss_state_store $007E, $0000
boss_state_pc_c2eaa2:
    boss_state_callnative $6EEB
boss_state_pc_c2eaa5:
    boss_state_duration14 $0001
boss_state_pc_c2eaa8:
    boss_state_end
boss_state_pc_c2eaa9:
    boss_state_anim $00F4
boss_state_pc_c2eaac:
    boss_state_duration14 $0024
boss_state_pc_c2eaaf:
    boss_state_c0_006c $006E
boss_state_pc_c2eab2:
    boss_state_end
boss_state_pc_c2eab3:
    boss_state_anim $00F4
boss_state_pc_c2eab6:
    boss_state_frames $0000, $0000, $0000, $0001, $0000, $0000
boss_state_pc_c2eac3:
    boss_state_speed90 $36BC
boss_state_pc_c2eac6:
    boss_state_c0_006c $006E
boss_state_pc_c2eac9:
    boss_state_duration14 $0018
boss_state_pc_c2eacc:
    boss_state_end
boss_state_pc_c2eacd:
    boss_state_anim $00F5
boss_state_pc_c2ead0:
    boss_state_store $007E, $8001
boss_state_pc_c2ead5:
    boss_state_c0_006c $006E
boss_state_pc_c2ead8:
    boss_state_end
boss_state_pc_c2ead9:
    boss_state_anim $00F6
boss_state_pc_c2eadc:
    boss_state_c0_006c $006E
boss_state_pc_c2eadf:
    boss_state_end
boss_state_pc_c2eae0:
    boss_state_anim $00F6
boss_state_pc_c2eae3:
    boss_state_frames $0000, $0000, $0000, $0001, $0000, $0000
boss_state_pc_c2eaf0:
    boss_state_speed90 $36BC
boss_state_pc_c2eaf3:
    boss_state_c0_006c $006E
boss_state_pc_c2eaf6:
    boss_state_duration14 $0018
boss_state_pc_c2eaf9:
    boss_state_end
boss_state_pc_c2eafa:
    boss_state_anim $00F8
boss_state_pc_c2eafd:
    boss_state_store $007E, $0001
boss_state_pc_c2eb02:
    boss_state_c0_006c $006E
boss_state_pc_c2eb05:
    boss_state_end
boss_state_pc_c2eb06:
    boss_state_anim $00F9
boss_state_pc_c2eb09:
    boss_state_c0_006c $006E
boss_state_pc_c2eb0c:
    boss_state_end
boss_state_pc_c2eb0d:
    boss_state_anim $00F7
boss_state_pc_c2eb10:
    boss_state_f4a $34B9
boss_state_pc_c2eb13:
    boss_state_end
boss_state_pc_c2eb14:
    boss_state_anim $00F4
boss_state_pc_c2eb17:
    boss_state_frames $0000, $0000, $0000, $FFFF, $0000, $0000
boss_state_pc_c2eb24:
    boss_state_speed90 $36BC
boss_state_pc_c2eb27:
    boss_state_duration14 $0018
boss_state_pc_c2eb2a:
    boss_state_c0_006c $006E
boss_state_pc_c2eb2d:
    boss_state_end
boss_state_pc_c2eb2e:
    boss_state_anim $00F6
boss_state_pc_c2eb31:
    boss_state_frames $0000, $0000, $0000, $FFFF, $0000, $0000
boss_state_pc_c2eb3e:
    boss_state_speed90 $36BC
boss_state_pc_c2eb41:
    boss_state_c0_006c $006E
boss_state_pc_c2eb44:
    boss_state_duration14 $0018
boss_state_pc_c2eb47:
    boss_state_end
boss_state_pc_c2eb48:
    boss_state_end
