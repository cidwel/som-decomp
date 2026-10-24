; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-sprite-pool.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
routine_7eb53d = $B53D

.segment "CODE"
.org $B42B
initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    pha
    .a8
    and #$02
    sta a:$02CF
    pla
    .a8
    and #$01
    sta a:$02CE
    xba
    sta $03
    stz a:$02D0
    .a8
    lda #$00
    .i16
    ldx #$0800
    jsr allocate_and_fill_bytes
    stx a:$02C8
    .i16
    ldx #$0220
    .a8
    lda #$00
    jsr allocate_and_fill_bytes
    stx a:$02CC
    .a8
    lda #$00
    .i16
    ldx #$0200
    jsr allocate_and_fill_bytes
    stx a:$02CA
    ldx a:$02C8
    .a8
    lda #$80
    sta $01
initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups_b47c:
    phx
    rep #$20
    .a16
    lda #$FFF0
    sta a:$0002,X
    stz a:$0004,X
    sep #$20
    .a8
    lda #$80
    sec
    sbc $01
    sta a:$000A,X
    lda $03
    lsr
    lsr
    sta a:$000B,X
    stz a:$0008,X
    jsr routine_7eb53d
    plx
    clc
    rep #$20
    txa
    .a16
    adc #$0010
    tax
    sep #$20
    dec $01
    bne initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups_b47c
    ldx a:$02CA
    ldy a:$02C8
    rep #$20
    .a16
    lda #$0020
    sta $01
initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups_b4bb:
    tya
    sta a:$0000,X
    tay
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sta a:$0002,X
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sta a:$0004,X
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sta a:$0006,X
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sep #$20
    .a8
    lda #$20
    sec
    sbc $01
    asl
    asl
    sta a:$0009,X
    asl
    sta a:$000A,X
    lda $03
    sta a:$000B,X
    rep #$20
    clc
    txa
    .a16
    adc #$0010
    tax
    dec $01
    bne initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups_b4bb
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
