; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $89A5
increase_native59_radius_or_clamp_to_parent_target:
    ldx $87
    lda a:$00B4,X
    cmp a:$00B8,X
    bcs increase_native59_radius_or_clamp_to_parent_target_c289b3
    inc a:$00B4,X
    rts
increase_native59_radius_or_clamp_to_parent_target_c289b3:
    lda a:$00B8,X
    sta a:$00B4,X
    rts
