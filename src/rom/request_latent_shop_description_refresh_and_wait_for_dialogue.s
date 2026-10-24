; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-shop-refresh-alias.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d0d5c1 = $D0D5C1

.segment "CODE"
.org $7FE8
request_latent_shop_description_refresh_and_wait_for_dialogue:
    .a8
    lda #$04
    tsb a:$1802
    jsl f:routine_d0d5c1
    rts
