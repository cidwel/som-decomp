; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_map_palette = $E022
routine_00e034 = $E034
routine_00e1a2 = $E1A2
routine_02a360 = $2A360
routine_02a39f = $2A39F
routine_c1d9c3 = $D9C3

.segment "CODE"
.org $D9C4
clone_action_actor_and_refresh_identity:
    jsl f:routine_02a360
    bcc routine_c1d9c3
    phx
    jsl f:routine_02a39f
    jsl f:routine_00e1a2
    jsr load_actor_map_palette
    sep #$20
    .a8
    lda #$01
    sta a:$E032,X
    jsl f:routine_00e034
    plx
    rtl
