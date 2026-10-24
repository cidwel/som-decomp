; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_map_graphics_resources = $1F403

.segment "CODE"
.org $C45E
reload_map_header_graphics:
    rep #$30
    lda $DC
    asl
    tax
    lda f:$C87000,X
    sta $1D
    sep #$30
    .a8
    lda #$C8
    sta $1F
    .i8
    ldy #$01
    lda [$1D],Y
    sta $1B
    .i8
    ldy #$00
    lda [$1D],Y
    sta $1C
    jsl f:initialize_map_graphics_resources
    rtl
