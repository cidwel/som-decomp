; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-animation.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb7b9 = $B7B9
routine_7ec288 = $C288

.segment "CODE"
.org $BA21
update_nine_warm_child_sprite_animation_records:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    stx $03
    lda a:$0012,X
    inc
    .a16
    cmp #$0004
    bcc update_nine_warm_child_sprite_animation_records_ba4f
    .a16
    lda #$0004
    jsr routine_7ec288
    tax
    beq update_nine_warm_child_sprite_animation_records_ba43
    .a16
    lda #$0008
update_nine_warm_child_sprite_animation_records_ba43:
    clc
    .a16
    adc #$0008
    ldx $03
    sta a:$0014,X
    .a16
    lda #$0000
update_nine_warm_child_sprite_animation_records_ba4f:
    sta a:$0012,X
    tax
    .a16
    lda #$0009
    sta $01
    lda f:$7E603A,X
    .a16
    and #$00FF
    ldx $03
update_nine_warm_child_sprite_animation_records_ba61:
    ldy a:$0000,X
    sta a:$0006,Y
    phx
    pha
    tyx
    jsr routine_7eb7b9
    pla
    plx
    inc
    inx
    inx
    dec $01
    bne update_nine_warm_child_sprite_animation_records_ba61
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
