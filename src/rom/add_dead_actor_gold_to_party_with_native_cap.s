; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

cap_combat_24bit_value_at_9999999 = $39A4

.segment "CODE"
.org $44F0
add_dead_actor_gold_to_party_with_native_cap:
    ldx $85
    rep #$20
    lda a:$E1C8,X
    clc
    adc a:$CC6A
    sta $D0
    sep #$20
    .a8
    lda #$00
    adc a:$CC6C
    sta $D2
    jsr cap_combat_24bit_value_at_9999999
    rep #$20
    lda $D0
    sta a:$CC6A
    sep #$20
    lda $D2
    sta a:$CC6C
    rts
