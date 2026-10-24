; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-menu-records.md.
.setcpu "65816"
.smart
.a8
.i16

advance_one_timed_menu_tile_record_and_publish_native_tiles = $BB0F

.segment "CODE"
.org $BAD6
advance_timed_menu_tile_records_on_even_frames:
    sep #$30
    lda $F4
    lsr
    bcs advance_timed_menu_tile_records_on_even_frames_c2bae1
    lda $9B
    bne advance_timed_menu_tile_records_on_even_frames_c2bae2
advance_timed_menu_tile_records_on_even_frames_c2bae1:
    rtl
advance_timed_menu_tile_records_on_even_frames_c2bae2:
    sta $00
    stz $01
    phb
    .a8
    lda #$7E
    pha
    plb
advance_timed_menu_tile_records_on_even_frames_c2baeb:
    sep #$30
    ldx $01
    dec a:$D202,X
    bpl advance_timed_menu_tile_records_on_even_frames_c2bb02
    lda a:$D203,X
    sta a:$D202,X
    lda a:$D200,X
    jsr advance_one_timed_menu_tile_record_and_publish_native_tiles
    sep #$30
advance_timed_menu_tile_records_on_even_frames_c2bb02:
    lda $01
    clc
    .a8
    adc #$10
    sta $01
    dec $00
    bne advance_timed_menu_tile_records_on_even_frames_c2baeb
    plb
    rtl
