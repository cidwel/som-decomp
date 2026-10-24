; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-shop-notice.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c00092 = $C00092
routine_c00095 = $C00095
routine_c07f93 = $7F93
routine_c07ff1 = $7FF1
routine_d0d5c1 = $D0D5C1

.segment "CODE"
.org $7FA8
display_latent_shop_notice_through_real_input_or_brk_prefix:
    rep #$30
    sep #$20
    .a8
    lda #$01
    bit a:$1D04
    beq display_latent_shop_notice_through_real_input_or_brk_prefix_c07fb9
    phx
    jsl f:routine_c00095
    plx
display_latent_shop_notice_through_real_input_or_brk_prefix_c07fb9:
    .a8
    lda #$D9
    sta a:$1D03
    stx a:$1D01
    jsl f:routine_c00092
    jsl f:routine_d0d5c1
display_latent_shop_notice_through_real_input_or_brk_prefix_c07fc9:
    rep #$30
    jsl f:routine_d0d5c1
    jsr routine_c07f93
    .a16
    bit #$CFC0
    bne display_latent_shop_notice_through_real_input_or_brk_prefix_c07fc9
display_latent_shop_notice_through_real_input_or_brk_prefix_c07fd7:
    jsr routine_c07f93
    .a16
    bit #$CFC0
    beq display_latent_shop_notice_through_real_input_or_brk_prefix_c07fd7
    sep #$20
    .a8
    lda #$80
    bit a:$1804
    bne routine_c07ff1
