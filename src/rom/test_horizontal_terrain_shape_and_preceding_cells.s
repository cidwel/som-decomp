; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-map-terrain-queries.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BC37
test_horizontal_terrain_shape_and_preceding_cells:
    sep #$20
    lda $1A
    sta $03
    stz $02
    lda $07
    .a8
    and #$07
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bc55
    .a8
    cmp #$04
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bc55
    .a8
    cmp #$03
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bc69
    eor $1B
    .a8
    and #$03
    .a8
    cmp #$03
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bc69
test_horizontal_terrain_shape_and_preceding_cells_c1bc55:
    lda $06
    .a8
    and #$07
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bc85
    lda $04
    sec
    sbc $03
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bc65
    brl test_horizontal_terrain_shape_and_preceding_cells_c1bd16
test_horizontal_terrain_shape_and_preceding_cells_c1bc65:
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bc67:
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bc69:
    lda $1E
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bc67
    lda $04
    .a8
    cmp #$08
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bc67
    .a8
    lda #$09
    bit $1F
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bc7b
    .a8
    lda #$08
test_horizontal_terrain_shape_and_preceding_cells_c1bc7b:
    sta $02
    lda $04
    sec
    sbc $03
    brl test_horizontal_terrain_shape_and_preceding_cells_c1bd16
test_horizontal_terrain_shape_and_preceding_cells_c1bc85:
    .a8
    cmp #$04
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bca3
    lda $04
    cmp $05
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bc95
test_horizontal_terrain_shape_and_preceding_cells_c1bc8f:
    .a8
    lda #$04
    sta $02
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bc95:
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bc8f
    sbc $03
    bmi test_horizontal_terrain_shape_and_preceding_cells_c1bc8f
    cmp $05
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bc8f
    bcc test_horizontal_terrain_shape_and_preceding_cells_c1bc8f
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bca3:
    .a8
    cmp #$05
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bcc8
    bit $1F
    bmi test_horizontal_terrain_shape_and_preceding_cells_c1bcb5
    lda $1E
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bcb5
    lda $04
    .a8
    cmp #$02
    bcc test_horizontal_terrain_shape_and_preceding_cells_c1bcc6
test_horizontal_terrain_shape_and_preceding_cells_c1bcb5:
    lda $04
    cmp $05
    bcc test_horizontal_terrain_shape_and_preceding_cells_c1bcc1
    .a8
    lda #$05
    sta $02
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bcc1:
    sec
    sbc $03
    bmi test_horizontal_terrain_shape_and_preceding_cells_c1bd16
test_horizontal_terrain_shape_and_preceding_cells_c1bcc6:
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bcc8:
    .a8
    cmp #$06
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bce9
    lda $04
    .a8
    eor #$0F
    cmp $05
    bcc test_horizontal_terrain_shape_and_preceding_cells_c1bcda
test_horizontal_terrain_shape_and_preceding_cells_c1bcd4:
    .a8
    lda #$06
    sta $02
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bcda:
    lda $04
    sec
    sbc $03
    bmi test_horizontal_terrain_shape_and_preceding_cells_c1bcd4
    .a8
    eor #$0F
    cmp $05
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bcd4
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bce9:
    .a8
    cmp #$07
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bd14
    bit $1F
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bcfb
    lda $1E
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bcfb
    lda $04
    .a8
    cmp #$02
    bcc test_horizontal_terrain_shape_and_preceding_cells_c1bd12
test_horizontal_terrain_shape_and_preceding_cells_c1bcfb:
    lda $04
    .a8
    eor #$0F
    cmp $05
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bd09
test_horizontal_terrain_shape_and_preceding_cells_c1bd03:
    .a8
    lda #$07
    sta $02
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bd09:
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bd03
    lda $04
    sec
    sbc $03
    bmi test_horizontal_terrain_shape_and_preceding_cells_c1bd16
test_horizontal_terrain_shape_and_preceding_cells_c1bd12:
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bd14:
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bd16:
    .a8
    eor #$FF
    inc
test_horizontal_terrain_shape_and_preceding_cells_c1bd19:
    sta $03
    .a8
    lda #$0F
    sta $04
    lda $08
    .a8
    and #$7F
    dec
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bd29
    lda $9C
    dec
test_horizontal_terrain_shape_and_preceding_cells_c1bd29:
    bit $08
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bd2f
    .a8
    ora #$80
test_horizontal_terrain_shape_and_preceding_cells_c1bd2f:
    sta $08
    ldy $08
    lda [$0A],Y
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    tay
    sep #$20
    lda [$0D],Y
    sta $07
    iny
    iny
    lda [$0D],Y
    sta $06
    .a8
    and #$F0
    .a8
    cmp #$10
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bd51
    stz $06
test_horizontal_terrain_shape_and_preceding_cells_c1bd51:
    lda $07
    .a8
    and #$07
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bd67
    .a8
    cmp #$04
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bd67
    .a8
    cmp #$03
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bd7e
    eor $1B
    .a8
    and #$03
    .a8
    cmp #$03
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bd7e
test_horizontal_terrain_shape_and_preceding_cells_c1bd67:
    lda $06
    .a8
    and #$07
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bd9d
    lda $03
    sec
    .a8
    sbc #$10
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bd19
    lda $02
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bd7c
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bd7a:
    stz $02
test_horizontal_terrain_shape_and_preceding_cells_c1bd7c:
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bd7e:
    lda $1E
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bd7a
    lda $02
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bd7a
    lda $04
    sec
    sbc $03
    bmi test_horizontal_terrain_shape_and_preceding_cells_c1bd7a
    .a8
    cmp #$08
    bcc test_horizontal_terrain_shape_and_preceding_cells_c1bd7a
    .a8
    lda #$08
    bit $1F
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bd99
    .a8
    lda #$09
test_horizontal_terrain_shape_and_preceding_cells_c1bd99:
    sta $02
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bd9d:
    .a8
    cmp #$04
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bdc8
    lda $04
    sec
    sbc $03
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bdae
test_horizontal_terrain_shape_and_preceding_cells_c1bda8:
    .a8
    lda #$04
    sta $02
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bdae:
    sta $04
    bit $1F
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bdbe
    lda $1E
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bdbe
    lda $04
    .a8
    cmp #$0E
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bdc6
test_horizontal_terrain_shape_and_preceding_cells_c1bdbe:
    lda $04
    cmp $05
    beq test_horizontal_terrain_shape_and_preceding_cells_c1bda8
    bcc test_horizontal_terrain_shape_and_preceding_cells_c1bda8
test_horizontal_terrain_shape_and_preceding_cells_c1bdc6:
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bdc8:
    .a8
    cmp #$05
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bdd8
    lda $02
    .a8
    cmp #$08
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bdd6
    .a8
    lda #$05
    sta $02
test_horizontal_terrain_shape_and_preceding_cells_c1bdd6:
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bdd8:
    .a8
    cmp #$06
    bne test_horizontal_terrain_shape_and_preceding_cells_c1be03
    lda $04
    sec
    sbc $03
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bde9
test_horizontal_terrain_shape_and_preceding_cells_c1bde3:
    .a8
    lda #$06
    sta $02
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1bde9:
    sta $04
    bit $1F
    bpl test_horizontal_terrain_shape_and_preceding_cells_c1bdf9
    lda $1E
    bne test_horizontal_terrain_shape_and_preceding_cells_c1bdf9
    lda $04
    .a8
    cmp #$0E
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1be01
test_horizontal_terrain_shape_and_preceding_cells_c1bdf9:
    lda $04
    .a8
    eor #$0F
    cmp $05
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1bde3
test_horizontal_terrain_shape_and_preceding_cells_c1be01:
    clc
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1be03:
    .a8
    cmp #$07
    bne test_horizontal_terrain_shape_and_preceding_cells_c1be13
    lda $02
    .a8
    cmp #$08
    bcs test_horizontal_terrain_shape_and_preceding_cells_c1be11
    .a8
    lda #$07
    sta $02
test_horizontal_terrain_shape_and_preceding_cells_c1be11:
    sec
    rts
test_horizontal_terrain_shape_and_preceding_cells_c1be13:
    clc
    rts
