; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8820
expand_title_text_row:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    lda f:$7E59F8,X
    beq row_stream_end
    sta $01                     ; remaining leading blanks
    sta $02                     ; total row byte count
    lda #$60
row_leading_blanks:
    sta a:$0000,Y
    iny
    iny
    dec $01
    bne row_leading_blanks
row_characters:
    inx
    lda f:$7E59F8,X
    beq row_row_end
    cmp #$20
    bne row_store_character
    lda #$60
row_store_character:
    sta a:$0000,Y
    iny
    iny
    inc $02
    bra row_characters
row_row_end:
    inx
row_padding:
    lda $02
    cmp #$20
    bcs row_return
    lda #$60
    sta a:$0000,Y
    iny
    iny
    inc $02
    bra row_padding
row_stream_end:
    ldx #$0000
row_return:
    pla
    pla
    plp
    pld
    rts
