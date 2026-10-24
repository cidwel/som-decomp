; Recovered Secret of Mana USA routine; behaviour documented in docs/latent-shop-tick.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0695e = $695E
routine_c06d30 = $6D30

.segment "CODE"
.org $7F93
tick_latent_shop_input_or_enter_literal_brk:
    jsr routine_c0695e
    sep #$20
    .a8
    lda #$40
    bit a:$1803
    beq tick_latent_shop_input_or_enter_literal_brk_c07fa2
    jsr routine_c06d30
tick_latent_shop_input_or_enter_literal_brk_c07fa2:
    rep #$20
    lda a:$1800
    rts
