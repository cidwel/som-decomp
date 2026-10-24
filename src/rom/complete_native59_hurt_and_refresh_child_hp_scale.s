; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native59_variant_hp_scaling = $876C
test_boss_negative_status_word = $34B0

.segment "CODE"
.org $874A
complete_native59_hurt_and_refresh_child_hp_scale:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$000C
    bcc complete_native59_hurt_and_refresh_child_hp_scale_c2876a
    jsr test_boss_negative_status_word
    bcc complete_native59_hurt_and_refresh_child_hp_scale_c2875e
    inc a:$0094,X
    clc
    rts
complete_native59_hurt_and_refresh_child_hp_scale_c2875e:
    .a16
    lda #$0001
    sta a:$0094,X
    stz a:$00B2,X
    jsr dispatch_native59_variant_hp_scaling
complete_native59_hurt_and_refresh_child_hp_scale_c2876a:
    clc
    rts
