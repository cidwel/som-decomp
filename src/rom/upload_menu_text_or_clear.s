; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_menu_text_video = $1C75

.segment "CODE"
.org $1C1A
upload_menu_text_or_clear:
    lda a:$1D05
    .a8
    cmp #$07
    beq upload_menu_text_or_clear_c01c74
    lda a:$1D11
    .a8
    and #$08
    beq upload_menu_text_or_clear_c01c2b
    jsr clear_menu_text_video
upload_menu_text_or_clear_c01c2b:
    lda a:$1D04
    .a8
    and #$40
    beq upload_menu_text_or_clear_c01c74
    .i16
    ldx #$5820
    lda a:$1D11
    .a8
    and #$01
    beq upload_menu_text_or_clear_c01c47
    .i16
    ldx #$5800
    stx a:$2116
    .i16
    ldx #$9400
    bra upload_menu_text_or_clear_c01c4d
upload_menu_text_or_clear_c01c47:
    stx a:$2116
    .i16
    ldx #$9C00
upload_menu_text_or_clear_c01c4d:
    stx a:$4372
    ldx a:$1D1A
    stx a:$4375
    sep #$20
    .a8
    lda #$01
    sta a:$4370
    .a8
    lda #$18
    sta a:$4371
    .a8
    lda #$7E
    sta a:$4374
    lda a:$1D04
    .a8
    and #$BD
    sta a:$1D04
    .a8
    lda #$80
    sta a:$420B
upload_menu_text_or_clear_c01c74:
    rts
