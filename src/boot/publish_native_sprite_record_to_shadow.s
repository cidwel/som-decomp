; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sprite-publish.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B53D
publish_native_sprite_record_to_shadow:
    phd
    php
    rep #$30
    phb
    phx
    tsc
    tcd
    sep #$20
    txy
    lda a:$000A,X
    sta $01
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    clc
    adc a:$02CC
    tax
    lda a:$0008,Y
    .a16
    and #$00FF
    beq publish_native_sprite_record_to_shadow_b579
    lda a:$0002,Y
    clc
    .a16
    adc #$0010
    .a16
    cmp #$00F0
    bcs publish_native_sprite_record_to_shadow_b579
    lda a:$0004,Y
    clc
    .a16
    adc #$0010
    .a16
    cmp #$0110
    bcc publish_native_sprite_record_to_shadow_b583
publish_native_sprite_record_to_shadow_b579:
    sep #$20
    .a8
    lda #$F0
    sta a:$0001,X
    jmp publish_native_sprite_record_to_shadow_b60c
publish_native_sprite_record_to_shadow_b583:
    sep #$20
    lda a:$000B,Y
    .a8
    and #$03
    asl
    asl
    asl
    pha
    lda a:$0001,Y
    .a8
    and #$07
    ora $01,S
    asl
    sta $01,S
    lda a:$0007,Y
    .a8
    and #$01
    ora $01,S
    sta $01,S
    lda a:$0000,Y
    .a8
    and #$C0
    ora $01,S
    sta a:$0003,X
    lda a:$0006,Y
    sta a:$0002,X
    lda a:$0002,Y
    sta a:$0001,X
    lda a:$0004,Y
    sta a:$0000,X
    lda a:$02CF
    bne publish_native_sprite_record_to_shadow_b60b
    lda a:$0000,Y
    .a8
    and #$02
    sta $01,S
    lda a:$0005,Y
    .a8
    and #$01
    ora $01,S
    sta $01,S
    lda $01
    .a8
    and #$03
    inc
    sta $02
    .a8
    lda #$03
    sta $03
    pla
publish_native_sprite_record_to_shadow_b5de:
    dec $02
    beq publish_native_sprite_record_to_shadow_b5ea
    asl
    asl
    asl $03
    asl $03
    bra publish_native_sprite_record_to_shadow_b5de
publish_native_sprite_record_to_shadow_b5ea:
    pha
    lda $03
    .a8
    eor #$FF
    sta $03
    lda $01
    lsr
    lsr
    rep #$20
    .a16
    and #$001F
    clc
    adc a:$02CC
    tax
    sep #$20
    lda a:$0200,X
    and $03
    ora $01,S
    sta a:$0200,X
publish_native_sprite_record_to_shadow_b60b:
    pla
publish_native_sprite_record_to_shadow_b60c:
    pla
    pla
    pla
    plp
    pld
    rts
