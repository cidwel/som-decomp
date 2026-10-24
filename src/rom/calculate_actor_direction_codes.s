; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

read_actor_y_minus_height_x = $0343
read_actor_y_minus_height_y = $032E

ACTOR_POSITION_X = $0020

.segment "CODE"
.org $0404
calculate_actor_direction_codes:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$000E
    tcd
    tcs
    stz $0B
    lda a:ACTOR_POSITION_X,X
    sec
    sbc a:ACTOR_POSITION_X,Y
    bcs calculate_actor_direction_codes_c10425
    .a16
    eor #$FFFF
    inc
    pha
    .a16
    lda #$0003
    sta $0B
    pla
calculate_actor_direction_codes_c10425:
    .a16
    bit #$FF00
    beq calculate_actor_direction_codes_c1043a
    .a16
    ora #$FF00
    .a16
    eor #$FFFF
    inc
    pha
    lda $0B
    .a16
    eor #$0003
    sta $0B
    pla
calculate_actor_direction_codes_c1043a:
    sta $01
    jsr read_actor_y_minus_height_y
    sta $0D
    jsr read_actor_y_minus_height_x
    sec
    sbc $0D
    bcs calculate_actor_direction_codes_c10456
    .a16
    eor #$FFFF
    inc
    pha
    lda $0B
    .a16
    ora #$000C
    sta $0B
    pla
calculate_actor_direction_codes_c10456:
    .a16
    bit #$FF00
    beq calculate_actor_direction_codes_c1046b
    .a16
    ora #$FF00
    .a16
    eor #$FFFF
    inc
    pha
    lda $0B
    .a16
    eor #$000C
    sta $0B
    pla
calculate_actor_direction_codes_c1046b:
    cmp $01
    beq calculate_actor_direction_codes_c10471
    bcs calculate_actor_direction_codes_c10480
calculate_actor_direction_codes_c10471:
    sta $05
    lda $01
    sta $03
    .a16
    lda #$0003
    sta $09
    sta $07
    bra calculate_actor_direction_codes_c1048d
calculate_actor_direction_codes_c10480:
    sta $03
    lda $01
    sta $05
    .a16
    lda #$000C
    sta $09
    sta $07
calculate_actor_direction_codes_c1048d:
    lda $03
    sec
    sbc $05
    lsr
    sta $01
    lsr
    clc
    adc $01
    cmp $05
    bcs calculate_actor_direction_codes_c104a2
    .a16
    lda #$000F
    sta $09
calculate_actor_direction_codes_c104a2:
    sep #$20
    .a8
    lda #$05
    eor $0B
    and $07
    sta $01
    lda $05
    .a8
    and #$F0
    ora $01
    xba
    .a8
    lda #$05
    eor $0B
    and $09
    sta $01
    .a8
    lda #$05
    eor $0B
    asl
    asl
    asl
    asl
    ora $01
    rep #$20
    sta $0D,S
    tsc
    clc
    .a16
    adc #$000C
    tcs
    pla
    plp
    pld
    rts
