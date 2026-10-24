; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1F5B
upload_complete_native_menu_oam_table:
    phb
    .a8
    lda #$00
    pha
    plb
    .i16
    ldx #$0000
    stx a:$2102
    .a8
    lda #$00
    sta a:$4370
    .a8
    lda #$04
    sta a:$4371
    .i16
    ldx #$9C00
    stx a:$4372
    .a8
    lda #$7E
    sta a:$4374
    .i16
    ldx #$0220
    stx a:$4375
    .a8
    lda #$80
    sta a:$420B
    plb
    rts
