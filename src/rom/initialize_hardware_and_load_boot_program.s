; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decompress_block = $4C30

.segment "CODE"
.org $4D0F
initialize_hardware_and_load_boot_program:
    .a8
    lda #$00
    sta a:$4200
    .a8
    lda #$80
    sta a:$2100
    .a8
    lda #$40
    sta a:$0104
    sta a:$0100
    .i16
    ldx #$4200
    .i16
    ldy #$000E
    .a8
    lda #$00
initialize_hardware_and_load_boot_program_c14d29:
    sta a:$0000,X
    inx
    dey
    bne initialize_hardware_and_load_boot_program_c14d29
    .a8
    lda #$FF
    sta a:$4201
    .a8
    lda #$7E
    .i16
    ldy #$8000
    xba
    .a8
    lda #$C7
    .i16
    ldx #$7C00
    jsr decompress_block
    rts
