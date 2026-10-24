; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

record_contact_presentation_byte_and_volume = $D285

.segment "CODE"
.org $D293
probe_map_cell_contact_and_update_live_tile:
    rep #$30
    lda a:$E0C0,X
    sta $04
    .a16
    lda #$1010
    sta $06
    lda $56
    .a16
    and #$000F
    beq probe_map_cell_contact_and_update_live_tile_c1d2b9
    dec
    beq probe_map_cell_contact_and_update_live_tile_c1d2c8
    dec
    beq probe_map_cell_contact_and_update_live_tile_c1d2d4
    dec
    beq probe_map_cell_contact_and_update_live_tile_c1d2b8
    lda $06
    sep #$20
    lsr
    xba
    lsr
    bra probe_map_cell_contact_and_update_live_tile_c1d2de
probe_map_cell_contact_and_update_live_tile_c1d2b8:
    rts
probe_map_cell_contact_and_update_live_tile_c1d2b9:
    lda $06
    sep #$20
    lsr
    .a8
    eor #$FF
    inc
    xba
    lsr
    .a8
    eor #$FF
    inc
    bra probe_map_cell_contact_and_update_live_tile_c1d2de
probe_map_cell_contact_and_update_live_tile_c1d2c8:
    lda $06
    sep #$20
    lsr
    xba
    lsr
    .a8
    eor #$FF
    inc
    bra probe_map_cell_contact_and_update_live_tile_c1d2de
probe_map_cell_contact_and_update_live_tile_c1d2d4:
    lda $06
    sep #$20
    lsr
    .a8
    eor #$FF
    inc
    xba
    lsr
probe_map_cell_contact_and_update_live_tile_c1d2de:
    clc
    adc $05
    sta $05
    xba
    clc
    adc $04
    sta $04
    .a8
    lda #$7F
    sta $02
    sta $08
    .a8
    lda #$01
    sta $82
    lda a:$E00B,X
    .i16
    ldy #$B800
    sty $06
    .i16
    ldy #$0000
    asl
    bcc probe_map_cell_contact_and_update_live_tile_c1d30d
    .a8
    lda #$80
    sta $82
    .i16
    ldy #$BC00
    sty $06
    .i16
    ldy #$4000
probe_map_cell_contact_and_update_live_tile_c1d30d:
    sty $00
    lda $04
    bmi probe_map_cell_contact_and_update_live_tile_c1d324
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$E002,X
    cmp $C0
    bcc probe_map_cell_contact_and_update_live_tile_c1d332
    sbc $C0
    bra probe_map_cell_contact_and_update_live_tile_c1d332
probe_map_cell_contact_and_update_live_tile_c1d324:
    rep #$20
    .a16
    ora #$FF00
    clc
    adc a:$E002,X
    bpl probe_map_cell_contact_and_update_live_tile_c1d332
    clc
    adc $C0
probe_map_cell_contact_and_update_live_tile_c1d332:
    lsr
    lsr
    lsr
    lsr
    sta $0A
    sep #$20
    lda $05
    bmi probe_map_cell_contact_and_update_live_tile_c1d34f
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$E004,X
    cmp $C2
    bcc probe_map_cell_contact_and_update_live_tile_c1d35d
    sbc $C2
    bra probe_map_cell_contact_and_update_live_tile_c1d35d
probe_map_cell_contact_and_update_live_tile_c1d34f:
    rep #$20
    .a16
    ora #$FF00
    clc
    adc a:$E004,X
    bpl probe_map_cell_contact_and_update_live_tile_c1d35d
    clc
    adc $C2
probe_map_cell_contact_and_update_live_tile_c1d35d:
    sta $04
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $0A
    clc
    adc $00
    sta $00
    lda [$00]
    .a16
    and #$00FF
    asl
    asl
    tay
    iny
    iny
    lda [$06],Y
    sep #$20
    sta $0A
    .a8
    and #$F0
    .a8
    cmp #$C0
    beq probe_map_cell_contact_and_update_live_tile_c1d3ab
    .a8
    cmp #$F0
    beq probe_map_cell_contact_and_update_live_tile_c1d389
probe_map_cell_contact_and_update_live_tile_c1d386:
    brl probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d389:
    lda a:$E02C,X
    beq probe_map_cell_contact_and_update_live_tile_c1d386
    lda $0E
    ora $0F
    bne probe_map_cell_contact_and_update_live_tile_c1d386
    lda $0A
    asl
    asl
    asl
    asl
    rep #$20
    lsr
    lsr
    lsr
    lsr
    .a16
    ora #$8000
    sta $0E
    stx $1C
    stz $1E
    bra probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d3ab:
    lda $0A
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc probe_map_cell_contact_and_update_live_tile_c1d3ef
    beq probe_map_cell_contact_and_update_live_tile_c1d3c3
    .a8
    cmp #$09
    beq probe_map_cell_contact_and_update_live_tile_c1d3d0
    .a8
    cmp #$0A
    beq probe_map_cell_contact_and_update_live_tile_c1d3dd
    .a8
    cmp #$0B
    beq probe_map_cell_contact_and_update_live_tile_c1d3e6
    bra probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d3c3:
    lda a:$E068,X
    .a8
    cmp #$01
    beq probe_map_cell_contact_and_update_live_tile_c1d3f4
    .a8
    cmp #$02
    beq probe_map_cell_contact_and_update_live_tile_c1d3f4
    bne probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d3d0:
    lda a:$E068,X
    .a8
    cmp #$03
    beq probe_map_cell_contact_and_update_live_tile_c1d3f4
    .a8
    cmp #$04
    beq probe_map_cell_contact_and_update_live_tile_c1d3f4
    bne probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d3dd:
    lda a:$E068,X
    .a8
    cmp #$05
    bcs probe_map_cell_contact_and_update_live_tile_c1d3f4
    bcc probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d3e6:
    lda a:$E068,X
    .a8
    cmp #$03
    bcc probe_map_cell_contact_and_update_live_tile_c1d3f4
    bcs probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d3ef:
    cmp a:$E068,X
    bne probe_map_cell_contact_and_update_live_tile_c1d425
probe_map_cell_contact_and_update_live_tile_c1d3f4:
    xba
    sta [$00]
    pha
    lda $82
    asl
    rep #$20
    lda $04
    bcc probe_map_cell_contact_and_update_live_tile_c1d40a
    sec
    sbc $AE
    bcs probe_map_cell_contact_and_update_live_tile_c1d411
    adc $C6
    bra probe_map_cell_contact_and_update_live_tile_c1d411
probe_map_cell_contact_and_update_live_tile_c1d40a:
    sec
    sbc $AA
    bcs probe_map_cell_contact_and_update_live_tile_c1d411
    adc $C6
probe_map_cell_contact_and_update_live_tile_c1d411:
    sep #$20
    sta $83
    pla
    .a8
    cmp #$C1
    beq probe_map_cell_contact_and_update_live_tile_c1d424
    lda $0A
    .a8
    and #$0F
    clc
    .a8
    adc #$D8
    jsr record_contact_presentation_byte_and_volume
probe_map_cell_contact_and_update_live_tile_c1d424:
    rts
probe_map_cell_contact_and_update_live_tile_c1d425:
    sep #$20
    stz $82
    rts
