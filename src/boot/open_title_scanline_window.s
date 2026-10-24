; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
build_title_window_scanline_table = $CE6B
create_and_enqueue_task = $AB88
dispatch_parent_messages = $D17F

.segment "CODE"
.org $D2FC
open_title_scanline_window:
    phd
    php
    rep #$30
    phb
    phx
    tsc
    tcd
    sep #$20
    .a8
    lda #$0E
    jsr allocate_ppu_register_entry
    .a8
    lda #$2F
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    .i16
    ldx #$5EA0
    .a8
    lda #$7E
    jsr create_and_enqueue_task
    sta a:$0312
    .i16
    ldx #$0000
    stx $02
open_title_scanline_window_d323:
    ldx $02
    inx
    inx
    .i16
    cpx #$0040
    beq open_title_scanline_window_d32e
    bcs open_title_scanline_window_d340
open_title_scanline_window_d32e:
    stx $02
    .i16
    ldy #$0070
    jsr build_title_window_scanline_table
    .i16
    ldx #$0003
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    bne open_title_scanline_window_d323
open_title_scanline_window_d340:
    sta $03,S
    pla
    pla
    pla
    plp
    pld
    rts
