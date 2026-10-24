; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-particle-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb7b9 = $B7B9

.segment "CODE"
.org $9793
publish_nine_native_title_particle_sprites_from_frame_offsets:
    php
    rep #$20
    lda $01
    .a16
    and #$00FF
    asl
    tax
    lda f:$7E5F26,X
    tay
    .i16
    ldx #$0000
    .a16
    lda #$0009
    sta $20
publish_nine_native_title_particle_sprites_from_frame_offsets_97aa:
    stx $22
    lda $0C,X
    tyx
    tay
    lda f:$7E5F26,X
    .a16
    and #$003F
    clc
    adc $07
    sta a:$0002,Y
    sep #$20
    lda f:$7E5F26,X
    inx
    eor f:$7E5F26,X
    eor $00
    .a8
    and #$C0
    sta a:$0000,Y
    rep #$20
    lda f:$7E5F26,X
    inx
    .a16
    and #$003F
    clc
    adc $0A
    sta a:$0004,Y
    phx
    tyx
    jsr routine_7eb7b9
    ply
    ldx $22
    inx
    inx
    dec $20
    bne publish_nine_native_title_particle_sprites_from_frame_offsets_97aa
    plp
    rts
