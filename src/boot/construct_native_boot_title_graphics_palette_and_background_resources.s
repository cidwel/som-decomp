; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-graphics-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
allocate_graphics_workspace_block = $81D6
allocate_palette_slot = $BBAB
allocate_ppu_register_entry = $C030
allocate_transfer_descriptor = $8FC7
append_oneshot_ppu_entry = $C097
copy_palette_colours = $BC9A
create_graphics_buffer = $809B
create_registered_vram_buffer = $C76D
queue_palette_upload = $BBFE
routine_7e9716 = $9716
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $CDBF
construct_native_boot_title_graphics_palette_and_background_resources:
    phd
    php
    rep #$30
    phb
    phx
    tsc
    tcd
    sep #$20
    .a8
    lda #$46
    .i16
    ldx #$0080
    jsr create_graphics_buffer
    .a8
    lda #$46
    jsr allocate_graphics_workspace_block
    stx a:$0308
    rep #$20
    .a16
    lda #$0001
    jsr allocate_transfer_descriptor
    .a16
    lda #$4000
    sta a:$0002,X
    lda a:$0308
    sta a:$000A,X
    .a16
    lda #$1000
    sta a:$0005,X
    sep #$20
    .a8
    lda #$7E
    sta a:$0004,X
    jsr submit_transfer_or_program_hdma
    .a8
    lda #$00
    jsr allocate_palette_slot
    stx a:$030A
    .a8
    lda #$7E
    .i16
    ldy #$5120
    xba
    .a8
    lda #$1D
    jsr copy_palette_colours
    ldx a:$030A
    jsr queue_palette_upload
    asl
    asl
    .a8
    ora #$20
    sta a:$0310
    .a8
    lda #$14
    jsr create_registered_vram_buffer
    stx a:$0306
    rep #$20
    lda a:$0306
    clc
    .a16
    adc #$0740
    tax
    jsr routine_7e9716
    sep #$20
    .a8
    lda #$2C
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    .a8
    ora #$02
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    .a8
    lda #$05
    jsr allocate_ppu_register_entry
    .a8
    lda #$03
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    .i16
    ldx #$0009
    .a8
    lda #$00
    jsr allocate_and_fill_bytes
    stx a:$030C
    pla
    pla
    pla
    plp
    pld
    rts
