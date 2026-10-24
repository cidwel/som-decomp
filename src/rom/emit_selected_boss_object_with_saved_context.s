; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_selected_boss_object_camera_palette_callback_and_sprites = $0F91

.segment "CODE"
.org $023A
emit_selected_boss_object_with_saved_context:
    php
    phd
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    jsr emit_selected_boss_object_camera_palette_callback_and_sprites
    plb
    pld
    plp
    rtl
