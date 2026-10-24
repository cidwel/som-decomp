; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $444A
store_selected_actor_weapon_experience_byte:
    ldy $CC
    lda a:$E1E4,Y
    sta $D4
    ldy $D4
    lda $D0
    sta a:$E1D0,Y
    rts
