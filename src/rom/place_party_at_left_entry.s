; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

set_party_cardinal_entry_velocity = $DEF3

.segment "CODE"
.org $DEAF
place_party_at_left_entry:
    rep #$10
    ldx $D4
    lda a:$E00B,X
    asl
    rep #$20
    lda $A8
    bcc place_party_at_left_entry_c1debf
    lda $AC
place_party_at_left_entry_c1debf:
    sta a:$E002
    sta a:$E202
    sta a:$E402
    .a16
    lda #$0002
    bra set_party_cardinal_entry_velocity
