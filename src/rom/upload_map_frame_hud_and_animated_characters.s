; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C238
upload_map_frame_hud_and_animated_characters:
    rep #$10
    sep #$20
    .a8
    lda #$5B
    xba
    stz a:$2115
    lda a:$0A55
    beq upload_map_frame_hud_and_animated_characters_c0c275
    tax
    stx a:$2116
    lda a:$0A56
    sta a:$2118
    lda a:$0A57
    sta a:$2118
    lda a:$0A50
    sta a:$2118
    lda a:$0A51
    sta a:$2118
    lda a:$0A52
    sta a:$2118
    lda a:$0A53
    sta a:$2118
    lda a:$0A54
    sta a:$2118
upload_map_frame_hud_and_animated_characters_c0c275:
    lda a:$0A65
    beq upload_map_frame_hud_and_animated_characters_c0c2a8
    tax
    stx a:$2116
    lda a:$0A66
    sta a:$2118
    lda a:$0A67
    sta a:$2118
    lda a:$0A60
    sta a:$2118
    lda a:$0A61
    sta a:$2118
    lda a:$0A62
    sta a:$2118
    lda a:$0A63
    sta a:$2118
    lda a:$0A64
    sta a:$2118
upload_map_frame_hud_and_animated_characters_c0c2a8:
    lda a:$0A75
    beq upload_map_frame_hud_and_animated_characters_c0c2db
    tax
    stx a:$2116
    lda a:$0A76
    sta a:$2118
    lda a:$0A77
    sta a:$2118
    lda a:$0A70
    sta a:$2118
    lda a:$0A71
    sta a:$2118
    lda a:$0A72
    sta a:$2118
    lda a:$0A73
    sta a:$2118
    lda a:$0A74
    sta a:$2118
upload_map_frame_hud_and_animated_characters_c0c2db:
    lda $52
    beq upload_map_frame_hud_and_animated_characters_c0c304
    .a8
    lda #$81
    sta a:$2115
    .i16
    ldx #$1801
    stx a:$4370
    .a8
    lda #$7F
    sta a:$4374
    .i16
    ldx #$FF00
    stx a:$4372
    ldx $74
    stx a:$2116
    .a8
    lda #$18
    sta a:$4375
    .a8
    lda #$80
    sta a:$420B
upload_map_frame_hud_and_animated_characters_c0c304:
    sep #$30
    lda $90
    bpl upload_map_frame_hud_and_animated_characters_c0c337
    .a8
    and #$7F
    sta $90
    rep #$20
    .i8
    ldx #$80
    stx a:$2115
    lda $92
    beq upload_map_frame_hud_and_animated_characters_c0c337
    sta a:$4372
    .i8
    ldx #$DC
    stx a:$4374
    lda $96
    sta a:$2116
    .a16
    lda #$0080
    sta a:$4375
    .a16
    lda #$1801
    sta a:$4370
    .i8
    ldx #$80
    stx a:$420B
upload_map_frame_hud_and_animated_characters_c0c337:
    sep #$30
    lda $9A
    bmi upload_map_frame_hud_and_animated_characters_c0c33e
    rts
upload_map_frame_hud_and_animated_characters_c0c33e:
    .a8
    and #$0F
    sta $9A
    tay
    .a8
    lda #$01
    sta a:$4370
    .a8
    lda #$18
    sta a:$4371
    .a8
    lda #$7F
    sta a:$4374
    .a8
    lda #$80
    sta a:$2115
    .i8
    ldx #$00
upload_map_frame_hud_and_animated_characters_c0c359:
    lda f:$7F8200,X
    bne upload_map_frame_hud_and_animated_characters_c0c368
upload_map_frame_hud_and_animated_characters_c0c35f:
    txa
    clc
    .a8
    adc #$10
    tax
    dey
    bne upload_map_frame_hud_and_animated_characters_c0c359
    rts
upload_map_frame_hud_and_animated_characters_c0c368:
    lda f:$7F8201,X
    .a8
    cmp #$08
    bcs upload_map_frame_hud_and_animated_characters_c0c3c1
    .a8
    cmp #$02
    bcc upload_map_frame_hud_and_animated_characters_c0c39a
    .a8
    cmp #$04
    bcs upload_map_frame_hud_and_animated_characters_c0c39a
    rep #$20
    lda f:$7F8300,X
    sta a:$2116
    lda f:$7F8302,X
    sta a:$2118
    lda f:$7F8304,X
    sta a:$2116
    lda f:$7F8306,X
    sta a:$2118
    sep #$20
    bra upload_map_frame_hud_and_animated_characters_c0c35f
upload_map_frame_hud_and_animated_characters_c0c39a:
    .a8
    cmp #$04
    beq upload_map_frame_hud_and_animated_characters_c0c3cd
    .a8
    cmp #$05
    beq upload_map_frame_hud_and_animated_characters_c0c3cd
    rep #$20
    lda f:$7F820C,X
    sta a:$2116
    lda f:$7F820A,X
    sta a:$4372
    .a16
    lda #$0020
    sta a:$4375
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    bra upload_map_frame_hud_and_animated_characters_c0c35f
upload_map_frame_hud_and_animated_characters_c0c3c1:
    .a8
    cmp #$0A
    beq upload_map_frame_hud_and_animated_characters_c0c3ed
    .a8
    cmp #$0B
    beq upload_map_frame_hud_and_animated_characters_c0c3ed
    .a8
    cmp #$0D
    beq upload_map_frame_hud_and_animated_characters_c0c3ed
upload_map_frame_hud_and_animated_characters_c0c3cd:
    rep #$20
    lda f:$7F820A,X
    sta a:$4372
    lda f:$7F820C,X
    sta a:$2116
    .a16
    lda #$0040
    sta a:$4375
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    jmp upload_map_frame_hud_and_animated_characters_c0c35f
upload_map_frame_hud_and_animated_characters_c0c3ed:
    rep #$20
    lda f:$7F8300,X
    sta a:$2116
    lda f:$7F8302,X
    sta a:$2118
    lda f:$7F8304,X
    sta a:$2116
    lda f:$7F8306,X
    sta a:$2118
    lda f:$7F8308,X
    sta a:$2116
    lda f:$7F830A,X
    sta a:$2118
    lda f:$7F830C,X
    sta a:$2116
    lda f:$7F830E,X
    sta a:$2118
    sep #$20
    jmp upload_map_frame_hud_and_animated_characters_c0c35f
