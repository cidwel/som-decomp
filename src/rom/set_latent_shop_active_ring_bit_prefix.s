; Original-executed prefix only; no returning API or following JSR is claimed.
.setcpu "65816"
.segment "CODE"
.org $7F43
latent_shop_active_bit_prefix:
    sep #$20
.a8
    lda #$40
    tsb a:$1803
