; Static native-mode continuation fragment. Callee ABI/return/reachability unclaimed.
.setcpu "65816"
.smart

latent_target_c07c94 = $7C94
latent_shop_input_tick = $7F93
latent_shop_description_refresh = $7FE8
latent_target_c07a47 = $7A47

.segment "CODE"
.org $7F4D
latent_shop_confirmation_continuation_fragment:
    sep #$20
    .a8
    lda #$80
    tsb a:$1804
    rep #$30
    .a16
    .i16
    ldx #$FF3C
    jsr latent_target_c07c94
    sep #$20
    .a8
    lda #$80
    trb a:$1804
latent_shop_confirmation_poll:
    sep #$20
    lda a:$1801
    cmp #$80
    beq latent_shop_confirmation_preserve_status
    cmp #$40
    beq latent_shop_confirmation_alternate_selection
    jsr latent_shop_input_tick
    bra latent_shop_confirmation_poll
latent_shop_confirmation_alternate_selection:
    sep #$20
    lda #$02
    tsb a:$1803
    jsr latent_shop_description_refresh
    sep #$20
    lda #$01
latent_shop_confirmation_preserve_status:
    php
    jsr latent_target_c07a47
    jsr latent_shop_input_tick
    sep #$20
    lda #$40
    trb a:$1803
    plp
    rts
.assert * = $7F93, error, "Unexpected latent continuation extent"
