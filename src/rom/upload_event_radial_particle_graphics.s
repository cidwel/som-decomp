; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01864d = $1864D

.segment "CODE"
.org $CD70
upload_event_radial_particle_graphics:
    .i16
    ldy #$0200
    sty $14
    sep #$20
    .a8
    lda #$83
    sta a:$E04F,Y
    jsl f:routine_01864d
    rep #$20
    lda a:$078C
    sta a:$BF8C
    lda a:$078E
    sta a:$BF8E
    lda a:$0790
    sta a:$BF90
    lda a:$0792
    sta a:$BF92
    lda a:$0794
    sta a:$BF94
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    .i16
    ldy #$1801
    sty a:$4370
    sty a:$4360
    .a8
    lda #$7E
    sta a:$4374
    sta a:$4364
    .a8
    lda #$02
    sta $EC
upload_event_radial_particle_graphics_c2cdbc:
    bit $EC
    bne upload_event_radial_particle_graphics_c2cdbc
    .i16
    ldy #$39E0
    sty a:$4372
    .a8
    lda #$80
    sta a:$2115
    .i16
    ldy #$7200
    sty a:$2116
    .a8
    lda #$04
upload_event_radial_particle_graphics_c2cdd3:
    pha
    .i16
    ldy #$0020
    sty a:$4375
    sty a:$4365
    .a8
    lda #$80
    sta a:$420B
    .i16
    ldy #$CB00
    sty a:$4362
    .a8
    lda #$40
    sta a:$420B
    pla
    dec
    bne upload_event_radial_particle_graphics_c2cdd3
    .i16
    ldy #$7300
    sty a:$2116
    .a8
    lda #$08
upload_event_radial_particle_graphics_c2cdf9:
    pha
    .i16
    ldy #$CB00
    sty a:$4362
    .i16
    ldy #$0020
    sty a:$4365
    .a8
    lda #$40
    sta a:$420B
    pla
    dec
    bne upload_event_radial_particle_graphics_c2cdf9
    plb
    rts
