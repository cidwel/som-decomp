; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_high = $E191

.segment "CODE"
.org $EFB6
lunar_set_status_0800_monsters:
    .i16
    ldy #$0600
    sty $CC
lunar_set_status_0800_monsters_c8efbb:
    ldy $CC
    lda a:object_status_high,Y
    .a8
    ora #$08
    sta a:object_status_high,Y
    inc $CD
    inc $CD
    lda $CD
    .a8
    cmp #$0C
    bne lunar_set_status_0800_monsters_c8efbb
    rts
