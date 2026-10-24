; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_map_graphics = $DFD3
routine_00df51 = $DF51

.segment "CODE"
.org $DA84
replace_action_actor_identity_and_reset_motion:
    .a8
    lda #$00
    sta a:$E043,X
    lda a:$E142,X
    sta a:$E03D,X
    sta a:$E180,X
    .a8
    lda #$01
    sta a:$E032,X
    jsr load_actor_map_graphics
    jsl f:routine_00df51
    sep #$20
    .a8
    lda #$FF
    sta a:$E030,X
    stz a:$E104,X
    stz a:$E100,X
    stz a:$E083,X
    stz a:$E084,X
    stz a:$E01C,X
    stz a:$E00A,X
    stz a:$E064,X
    stz a:$E062,X
    rtl
