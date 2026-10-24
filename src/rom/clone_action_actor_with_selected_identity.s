; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_map_graphics = $DFD3
routine_00df51 = $DF51
routine_00e1a2 = $E1A2
routine_02a360 = $2A360
routine_02a39f = $2A39F
routine_c1da53 = $DA53

.segment "CODE"
.org $DA54
clone_action_actor_with_selected_identity:
    jsl f:routine_02a360
    bcc routine_c1da53
    phx
    jsl f:routine_02a39f
    sep #$20
    lda a:$E141,X
    sta a:$E03D,X
    sta a:$E180,X
    .a8
    lda #$01
    sta a:$E032,X
    sta a:$E000,X
    .a8
    lda #$00
    sta a:$E043,X
    jsl f:routine_00e1a2
    jsr load_actor_map_graphics
    jsl f:routine_00df51
    plx
    rtl
