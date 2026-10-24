; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $859B
copy_object_weapon_palette:
    phx
    sta f:$004202
    .a8
    lda #$0A
    sta f:$004203
    ldy a:$E0FA,X
    nop
    rep #$20
    lda f:$004216
    tax
    lda f:$D1F600,X
    sta a:$0700,Y
    lda f:$D1F602,X
    sta a:$0702,Y
    lda f:$D1F604,X
    sta a:$0704,Y
    lda f:$D1F606,X
    sta a:$0706,Y
    lda f:$D1F608,X
    sta a:$0708,Y
    plx
    sep #$20
    rts
