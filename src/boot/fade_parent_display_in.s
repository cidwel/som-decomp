; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
dispatch_parent_messages = $D17F

.segment "CODE"
.org $D20D
fade_parent_display_in:
    phd
    php
    rep #$30
    sep #$20
fade_parent_display_in_d213:
    .i16
    ldx #$0004
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    beq fade_parent_display_in_d23b
    lda a:$0314
    bne fade_parent_display_in_d213
    .a8
    lda #$00
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    cmp #$0F
    bcs fade_parent_display_in_d23b
    inc
    sta a:$0002,X
    pha
    jsr append_oneshot_ppu_entry
    pla
    .a8
    cmp #$0F
    bcc fade_parent_display_in_d213
fade_parent_display_in_d23b:
    plp
    pld
    rts
