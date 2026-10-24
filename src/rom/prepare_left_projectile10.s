; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-grandchildren.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_attack_row_then_create_parent_projectile = $82C0

.segment "CODE"
.org $820D
prepare_left_projectile10:
    .a16
    lda #$0018
    sta $95
    stz $97
    .a16
    lda #$0010
    jsr prepare_attack_row_then_create_parent_projectile
    rts
