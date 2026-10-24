; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

set_party_cardinal_entry_velocity = $DEF3

.segment "CODE"
.org $DE69
place_party_at_top_entry:
    rep #$10
    ldx $D4
    lda a:$E00B,X
    asl
    rep #$20
    lda $AA
    bcc place_party_at_top_entry_c1de79
    lda $AE
place_party_at_top_entry_c1de79:
    sta a:$E004
    sta a:$E204
    sta a:$E404
    .a16
    lda #$0200
    bra set_party_cardinal_entry_velocity
