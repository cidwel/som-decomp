; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
apply_ppu_queue_shadow = $C18B
initialize_copy_queue_pool = $C8C8
routine_7e8000 = $8000
routine_7e8f08 = $8F08
routine_7ea2eb = $A2EB
routine_7ea826 = $A826
routine_7eaf3c = $AF3C
routine_7eb129 = $B129
routine_7ebb67 = $BB67
routine_7ebf6e = $BF6E
routine_7ebfda = $BFDA
routine_7ec2d9 = $C2D9
routine_7ec6b1 = $C6B1
routine_7ecb57 = $CB57
routine_7ed5c4 = $D5C4
write_ppu_queue_entries = $C0FD

.segment "CODE"
.org $AD75
initialize_boot_resources:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$032E
    sec
    .a16
    sbc #$0000
    tax
    jsr routine_7eaf3c
    .a16
    lda #$007E
    .i16
    ldy #$5000
    xba
    .a16
    ora #$00C7
    .i16
    ldx #$B480
    jsl f:$C10014
    jsr routine_7ebf6e
    jsr routine_7ebfda
    jsr write_ppu_queue_entries
    jsr apply_ppu_queue_shadow
    jsr initialize_copy_queue_pool
    inc a:$0010
    lda f:$306001
    eor f:$306401
    eor f:$306801
    eor f:$306C01
    tax
    jsr routine_7ec2d9
    jsr routine_7ea826
    jsr routine_7eb129
    jsr routine_7ecb57
    jsr routine_7ea2eb
    jsr routine_7e8f08
    jsr routine_7ed5c4
    jsr routine_7ebb67
    jsr routine_7e8000
    jsr routine_7ec6b1
    .a16
    lda #$007E
    .i16
    ldy #$2000
    xba
    .a16
    ora #$00DC
    .i16
    ldx #$F240
    jsl f:$C10014
    .a16
    lda #$007E
    .i16
    ldy #$4000
    xba
    .a16
    ora #$00DC
    .i16
    ldx #$E800
    jsl f:$C10014
    .a16
    lda #$007E
    .i16
    ldy #$4C00
    xba
    .a16
    ora #$00C7
    .i16
    ldx #$C1C0
    jsl f:$C10014
    .a16
    lda #$0000
    jsr allocate_ppu_register_entry
    .a16
    lda #$0000
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    dec a:$0010
    plb
    plp
    pld
    rts
