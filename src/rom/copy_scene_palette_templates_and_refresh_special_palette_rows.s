; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-music-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16

copy_three_special_palette_rows_through_shared_tail = $FCF7

.segment "CODE"
.org $F8E9
copy_scene_palette_templates_and_refresh_special_palette_rows:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$000F
    sta $00
    .i16
    ldx #$7E00
    bit $E2
    bvc copy_scene_palette_templates_and_refresh_special_palette_rows_c1f901
    .i16
    ldx #$4840
copy_scene_palette_templates_and_refresh_special_palette_rows_c1f901:
    .i16
    ldy #$0002
    stz a:$0600
    stz a:$DE00
copy_scene_palette_templates_and_refresh_special_palette_rows_c1f90a:
    lda f:$C60000,X
    sta a:$0600,Y
    .a16
    and #$FFE0
    sta a:$DE00,Y
    iny
    iny
    dec $00
    bne copy_scene_palette_templates_and_refresh_special_palette_rows_c1f924
    iny
    iny
    .a16
    lda #$000F
    sta $00
copy_scene_palette_templates_and_refresh_special_palette_rows_c1f924:
    inx
    inx
    .i16
    cpy #$01E0
    bcc copy_scene_palette_templates_and_refresh_special_palette_rows_c1f90a
    sep #$20
    .a8
    lda #$01
    trb $F5
    .a8
    lda #$C0
    trb $F4
    plb
    lda $8C
    beq copy_scene_palette_templates_and_refresh_special_palette_rows_c1f943
    lda $E3
    .a8
    and #$0F
    bne copy_scene_palette_templates_and_refresh_special_palette_rows_c1f943
    jsr copy_three_special_palette_rows_through_shared_tail
copy_scene_palette_templates_and_refresh_special_palette_rows_c1f943:
    rts
