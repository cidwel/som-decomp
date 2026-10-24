; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-motion-collapse.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $90E4
publish_native7f_actor_mask_to_party_and_collision_byte:
    sep #$20
    ldx $8B
    lda f:$C205F0,X
    sta $95
    ora a:$E059
    sta a:$E059
    lda $95
    ora a:$E259
    sta a:$E259
    lda $95
    ora a:$E459
    sta a:$E459
    ldx $87
    .a8
    lda #$07
    sta a:$005A,X
    rep #$20
    rts
