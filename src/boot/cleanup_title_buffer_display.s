; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
release_title_auxiliary_buffer = $88CF
release_transfer_descriptor = $9066

.segment "CODE"
.org $8CA6
cleanup_title_buffer_display:
    phd
    php
    rep #$30
    sep #$20
    ldx a:$003A
    jsr release_transfer_descriptor
    ldx #$004A
    jsr release_title_auxiliary_buffer
    ldx #$0046
    jsr release_title_auxiliary_buffer
    ldx #$0042
    jsr release_title_auxiliary_buffer
    ldx a:$0040
    jsr release_transfer_descriptor
    ldx a:$003E
    jsr release_transfer_descriptor
    ldx a:$003C
    jsr release_transfer_descriptor
    lda #$26
    jsr allocate_ppu_register_entry
    lda #$00
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$30
    jsr allocate_ppu_register_entry
    lda #$30
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$31
    jsr allocate_ppu_register_entry
    lda #$00
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$2E
    jsr allocate_ppu_register_entry
    lda #$00
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$23
    jsr allocate_ppu_register_entry
    lda #$00
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    plp
    pld
    rts
