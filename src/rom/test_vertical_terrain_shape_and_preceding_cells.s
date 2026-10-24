; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-map-terrain-queries.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BE15
test_vertical_terrain_shape_and_preceding_cells:
    sep #$20
    .a8
    lda #$08
    sta $03
    stz $02
    lda $07
    .a8
    and #$07
    beq test_vertical_terrain_shape_and_preceding_cells_c1be33
    .a8
    cmp #$04
    bcs test_vertical_terrain_shape_and_preceding_cells_c1be33
    .a8
    cmp #$03
    beq test_vertical_terrain_shape_and_preceding_cells_c1be47
    eor $1B
    .a8
    and #$03
    .a8
    cmp #$03
    beq test_vertical_terrain_shape_and_preceding_cells_c1be47
test_vertical_terrain_shape_and_preceding_cells_c1be33:
    lda $06
    .a8
    and #$07
    bne test_vertical_terrain_shape_and_preceding_cells_c1be64
    lda $05
    sec
    sbc $03
    bpl test_vertical_terrain_shape_and_preceding_cells_c1be43
test_vertical_terrain_shape_and_preceding_cells_c1be40:
    brl test_vertical_terrain_shape_and_preceding_cells_c1bef6
test_vertical_terrain_shape_and_preceding_cells_c1be43:
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1be45:
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1be47:
    lda $1F
    bne test_vertical_terrain_shape_and_preceding_cells_c1be45
    lda $05
    .a8
    cmp #$08
    bcs test_vertical_terrain_shape_and_preceding_cells_c1be45
    .a8
    lda #$09
    bit $1E
    bpl test_vertical_terrain_shape_and_preceding_cells_c1be59
    .a8
    lda #$08
test_vertical_terrain_shape_and_preceding_cells_c1be59:
    sta $02
    lda $05
    sec
    sbc $03
    bmi test_vertical_terrain_shape_and_preceding_cells_c1be40
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1be64:
    .a8
    cmp #$04
    bne test_vertical_terrain_shape_and_preceding_cells_c1be89
    bit $1E
    bmi test_vertical_terrain_shape_and_preceding_cells_c1be76
    lda $1F
    bne test_vertical_terrain_shape_and_preceding_cells_c1be76
    lda $05
    .a8
    cmp #$04
    bcc test_vertical_terrain_shape_and_preceding_cells_c1be87
test_vertical_terrain_shape_and_preceding_cells_c1be76:
    lda $05
    cmp $04
    bcc test_vertical_terrain_shape_and_preceding_cells_c1be82
    .a8
    lda #$04
    sta $02
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1be82:
    sec
    sbc $03
    bmi test_vertical_terrain_shape_and_preceding_cells_c1bef6
test_vertical_terrain_shape_and_preceding_cells_c1be87:
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1be89:
    .a8
    cmp #$05
    bne test_vertical_terrain_shape_and_preceding_cells_c1bea8
    lda $05
    cmp $04
    bcs test_vertical_terrain_shape_and_preceding_cells_c1be99
test_vertical_terrain_shape_and_preceding_cells_c1be93:
    .a8
    lda #$05
    sta $02
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1be99:
    beq test_vertical_terrain_shape_and_preceding_cells_c1be93
    sec
    sbc $03
    bmi test_vertical_terrain_shape_and_preceding_cells_c1be93
    cmp $04
    bcc test_vertical_terrain_shape_and_preceding_cells_c1be93
    beq test_vertical_terrain_shape_and_preceding_cells_c1be93
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bea8:
    .a8
    cmp #$06
    bne test_vertical_terrain_shape_and_preceding_cells_c1bec9
    lda $04
    .a8
    eor #$0F
    cmp $05
    bcc test_vertical_terrain_shape_and_preceding_cells_c1beba
test_vertical_terrain_shape_and_preceding_cells_c1beb4:
    .a8
    lda #$06
    sta $02
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1beba:
    lda $05
    sec
    sbc $03
    bmi test_vertical_terrain_shape_and_preceding_cells_c1beb4
    .a8
    eor #$0F
    cmp $04
    bcs test_vertical_terrain_shape_and_preceding_cells_c1beb4
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bec9:
    .a8
    cmp #$07
    bne test_vertical_terrain_shape_and_preceding_cells_c1bef4
    bit $1E
    bpl test_vertical_terrain_shape_and_preceding_cells_c1bedb
    lda $1F
    bne test_vertical_terrain_shape_and_preceding_cells_c1bedb
    lda $05
    .a8
    cmp #$04
    bcc test_vertical_terrain_shape_and_preceding_cells_c1bef2
test_vertical_terrain_shape_and_preceding_cells_c1bedb:
    lda $04
    .a8
    eor #$0F
    cmp $05
    bcs test_vertical_terrain_shape_and_preceding_cells_c1bee9
test_vertical_terrain_shape_and_preceding_cells_c1bee3:
    .a8
    lda #$07
    sta $02
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bee9:
    beq test_vertical_terrain_shape_and_preceding_cells_c1bee3
    lda $05
    sec
    sbc $03
    bmi test_vertical_terrain_shape_and_preceding_cells_c1bef6
test_vertical_terrain_shape_and_preceding_cells_c1bef2:
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bef4:
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bef6:
    .a8
    eor #$FF
    inc
    sta $03
    .a8
    lda #$0F
    sta $05
    lda $09
    asl $08
    rol
    .a8
    and #$7F
    dec
    bpl test_vertical_terrain_shape_and_preceding_cells_c1bf0c
    lda $9D
    dec
test_vertical_terrain_shape_and_preceding_cells_c1bf0c:
    lsr
    sta $09
    ror $08
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
    beq test_vertical_terrain_shape_and_preceding_cells_c1bf31
    stz $06
test_vertical_terrain_shape_and_preceding_cells_c1bf31:
    lda $07
    .a8
    and #$07
    beq test_vertical_terrain_shape_and_preceding_cells_c1bf47
    .a8
    cmp #$04
    bcs test_vertical_terrain_shape_and_preceding_cells_c1bf47
    .a8
    cmp #$03
    beq test_vertical_terrain_shape_and_preceding_cells_c1bf57
    eor $1B
    .a8
    and #$03
    .a8
    cmp #$03
    beq test_vertical_terrain_shape_and_preceding_cells_c1bf57
test_vertical_terrain_shape_and_preceding_cells_c1bf47:
    lda $06
    .a8
    and #$07
    bne test_vertical_terrain_shape_and_preceding_cells_c1bf74
    lda $02
    bne test_vertical_terrain_shape_and_preceding_cells_c1bf55
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bf53:
    stz $02
test_vertical_terrain_shape_and_preceding_cells_c1bf55:
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bf57:
    lda $1F
    bne test_vertical_terrain_shape_and_preceding_cells_c1bf53
    lda $02
    bne test_vertical_terrain_shape_and_preceding_cells_c1bf53
    lda $05
    sec
    sbc $03
    .a8
    cmp #$08
    bcc test_vertical_terrain_shape_and_preceding_cells_c1bf53
    .a8
    lda #$08
    bit $1E
    bpl test_vertical_terrain_shape_and_preceding_cells_c1bf70
    .a8
    lda #$09
test_vertical_terrain_shape_and_preceding_cells_c1bf70:
    sta $02
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bf74:
    .a8
    cmp #$04
    bne test_vertical_terrain_shape_and_preceding_cells_c1bf84
    lda $02
    .a8
    cmp #$08
    bcs test_vertical_terrain_shape_and_preceding_cells_c1bf82
    .a8
    lda #$04
    sta $02
test_vertical_terrain_shape_and_preceding_cells_c1bf82:
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bf84:
    .a8
    cmp #$05
    bne test_vertical_terrain_shape_and_preceding_cells_c1bfa9
    bit $1E
    bpl test_vertical_terrain_shape_and_preceding_cells_c1bf96
    lda $1F
    bne test_vertical_terrain_shape_and_preceding_cells_c1bf96
    lda $05
    .a8
    cmp #$0C
    bcs test_vertical_terrain_shape_and_preceding_cells_c1bfa7
test_vertical_terrain_shape_and_preceding_cells_c1bf96:
    lda $05
    sec
    sbc $03
    cmp $04
    bcs test_vertical_terrain_shape_and_preceding_cells_c1bfa5
test_vertical_terrain_shape_and_preceding_cells_c1bf9f:
    .a8
    lda #$05
    sta $02
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bfa5:
    beq test_vertical_terrain_shape_and_preceding_cells_c1bf9f
test_vertical_terrain_shape_and_preceding_cells_c1bfa7:
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bfa9:
    .a8
    cmp #$06
    bne test_vertical_terrain_shape_and_preceding_cells_c1bfce
    bit $1E
    bmi test_vertical_terrain_shape_and_preceding_cells_c1bfbb
    lda $1F
    bne test_vertical_terrain_shape_and_preceding_cells_c1bfbb
    lda $05
    .a8
    cmp #$0C
    bcs test_vertical_terrain_shape_and_preceding_cells_c1bfcc
test_vertical_terrain_shape_and_preceding_cells_c1bfbb:
    lda $05
    sec
    sbc $03
    .a8
    eor #$0F
    cmp $04
    bcc test_vertical_terrain_shape_and_preceding_cells_c1bfcc
    .a8
    lda #$06
    sta $02
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bfcc:
    clc
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bfce:
    .a8
    cmp #$07
    bne test_vertical_terrain_shape_and_preceding_cells_c1bfde
    lda $02
    .a8
    cmp #$08
    bcs test_vertical_terrain_shape_and_preceding_cells_c1bfdc
    .a8
    lda #$07
    sta $02
test_vertical_terrain_shape_and_preceding_cells_c1bfdc:
    sec
    rts
test_vertical_terrain_shape_and_preceding_cells_c1bfde:
    clc
    rts
