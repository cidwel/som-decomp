; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9DE9
hide_unused_ui_sprite_slots:
    rep #$20
    sep #$10
    ldx $7C
hide_unused_ui_sprite_slots_c09def:
    .a16
    lda #$E0FF
    sta a:$0800,X
    inx
    inx
    inx
    inx
    bne hide_unused_ui_sprite_slots_c09def
    rts
