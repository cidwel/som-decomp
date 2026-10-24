; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

map_header_reserved_return = $C45D
initialize_map_scroll_animation = $1B0EC
initialize_map_character_animation = $1B17E
initialize_map_graphics_resources = $1F403
initialize_map_tile_attributes_and_words = $2A000
apply_map_header_transition_flags = $2AB03
initialize_map_palette_animation = $2BC7E
select_map_object_palette_rows = $C524

.segment "CODE"
.org $C481
initialize_map_header_resources:
    rep #$30
    lda $DC
    asl
    tax
    lda f:$C87000,X
    sta $1D
    lda f:$C87002,X
    pha
    sep #$30
    .a8
    lda #$C8
    sta $1F
    .i8
    ldy #$03
    lda [$1D],Y
    sta $B8
    .i8
    ldy #$01
    lda [$1D],Y
    sta $1B
    .i8
    ldy #$00
    lda [$1D],Y
    sta $1C
    jsl f:initialize_map_graphics_resources
    jsl f:initialize_map_scroll_animation
    jsl f:initialize_map_character_animation
    sep #$30
    .i8
    ldy #$01
    lda [$1D],Y
    sta $1C
    jsl f:initialize_map_palette_animation
    sep #$30
    .i8
    ldy #$02
    lda [$1D],Y
    sta $1C
    jsl f:initialize_map_tile_attributes_and_words
    sep #$30
    .i8
    ldy #$03
    lda [$1D],Y
    jsr map_header_reserved_return
    sep #$30
    .i8
    ldy #$04
    lda [$1D],Y
    jsl f:apply_map_header_transition_flags
    sep #$30
    .i8
    ldy #$05
    lda [$1D],Y
    sta $30
    .a8
    and #$C0
    .a8
    cmp #$40
    bne initialize_map_header_resources_c0c4f3
    .a8
    lda #$08
    sta $99
initialize_map_header_resources_c0c4f3:
    sep #$30
    .i8
    ldy #$06
    lda [$1D],Y
    sta $94
    sep #$30
    .i8
    ldy #$07
    lda [$1D],Y
    jsr select_map_object_palette_rows
    rep #$20
    lda $1D
    clc
    .a16
    adc #$0008
    sta f:$7EE802
    lda $1F
    sta f:$7EE804
    pla
    sec
    sbc f:$7EE802
    lsr
    lsr
    lsr
    sta f:$7EE800
    rts
