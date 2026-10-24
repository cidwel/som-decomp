; Recovered Secret of Mana USA routine; behaviour documented in docs/map-motion-shared.md.
.setcpu "65816"
.smart
.a8
.i16

limit_hero_signed_motion_to_live_party_window = $D6C8
routine_01b93e = $1B93E

.segment "CODE"
.org $D74F
resolve_actor_terrain_motion_and_publish_cell_layer:
    sep #$20
    rep #$10
    .a8
    lda #$7F
    sta $0F
    sta $0C
    lda $1B
    bmi resolve_actor_terrain_motion_and_publish_cell_layer_c0d769
    .i16
    ldx #$0000
    stx $0A
    .i16
    ldx #$B800
    stx $0D
    bra resolve_actor_terrain_motion_and_publish_cell_layer_c0d773
resolve_actor_terrain_motion_and_publish_cell_layer_c0d769:
    .i16
    ldx #$4000
    stx $0A
    .i16
    ldx #$BC00
    stx $0D
resolve_actor_terrain_motion_and_publish_cell_layer_c0d773:
    .i16
    ldx #$0000
    stx $1C
    sep #$20
    lda $11
    .a8
    cmp #$06
    bcs resolve_actor_terrain_motion_and_publish_cell_layer_c0d7aa
    lda a:$CF01
    lsr
    bcs resolve_actor_terrain_motion_and_publish_cell_layer_c0d7a7
    lda $FF
    .a8
    bit #$20
    beq resolve_actor_terrain_motion_and_publish_cell_layer_c0d792
    lda $E1
    .a8
    cmp #$05
    bcc resolve_actor_terrain_motion_and_publish_cell_layer_c0d7a7
resolve_actor_terrain_motion_and_publish_cell_layer_c0d792:
    lda $F1
    ora $4E
    bmi resolve_actor_terrain_motion_and_publish_cell_layer_c0d7a7
    lda $D0
    beq resolve_actor_terrain_motion_and_publish_cell_layer_c0d7aa
    lda a:$E00E
    ora a:$E20E
    ora a:$E40E
    bpl resolve_actor_terrain_motion_and_publish_cell_layer_c0d7aa
resolve_actor_terrain_motion_and_publish_cell_layer_c0d7a7:
    brl resolve_actor_terrain_motion_and_publish_cell_layer_c0d7f3
resolve_actor_terrain_motion_and_publish_cell_layer_c0d7aa:
    jsl f:routine_01b93e
    bcc resolve_actor_terrain_motion_and_publish_cell_layer_c0d7b7
    rts
resolve_actor_terrain_motion_and_publish_cell_layer_c0d7b1:
    rep #$20
    stz $1E
    sec
    rts
resolve_actor_terrain_motion_and_publish_cell_layer_c0d7b7:
    sep #$20
    lda $11
    .a8
    cmp #$06
    bcs resolve_actor_terrain_motion_and_publish_cell_layer_c0d7f3
    lda $1C
    beq resolve_actor_terrain_motion_and_publish_cell_layer_c0d7da
    lda $1E
    beq resolve_actor_terrain_motion_and_publish_cell_layer_c0d7f3
    lda $1F
    sta $1C
    stz $1F
    jsr limit_hero_signed_motion_to_live_party_window
    bcs resolve_actor_terrain_motion_and_publish_cell_layer_c0d7b1
    sep #$20
    lda $1C
    sta $1F
    bra resolve_actor_terrain_motion_and_publish_cell_layer_c0d7f3
resolve_actor_terrain_motion_and_publish_cell_layer_c0d7da:
    lda $1D
    beq resolve_actor_terrain_motion_and_publish_cell_layer_c0d7f3
    lda $1F
    beq resolve_actor_terrain_motion_and_publish_cell_layer_c0d7f3
    lda $1E
    sta $1D
    stz $1E
    jsr limit_hero_signed_motion_to_live_party_window
    bcs resolve_actor_terrain_motion_and_publish_cell_layer_c0d7b1
    sep #$20
    lda $1D
    sta $1E
resolve_actor_terrain_motion_and_publish_cell_layer_c0d7f3:
    sep #$20
    rep #$10
    lda $1E
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$007F
    bcs resolve_actor_terrain_motion_and_publish_cell_layer_c0d80d
    clc
    adc $12
    cmp $C0
    bcc resolve_actor_terrain_motion_and_publish_cell_layer_c0d818
    sbc $C0
    bra resolve_actor_terrain_motion_and_publish_cell_layer_c0d818
resolve_actor_terrain_motion_and_publish_cell_layer_c0d80d:
    .a16
    eor #$FFFF
    sec
    adc $12
    bpl resolve_actor_terrain_motion_and_publish_cell_layer_c0d818
    clc
    adc $C0
resolve_actor_terrain_motion_and_publish_cell_layer_c0d818:
    lsr
    lsr
    lsr
    lsr
    sta $08
    sep #$20
    lda $1F
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$007F
    bcs resolve_actor_terrain_motion_and_publish_cell_layer_c0d836
    clc
    adc $14
    cmp $C2
    bcc resolve_actor_terrain_motion_and_publish_cell_layer_c0d841
    sbc $C2
    bra resolve_actor_terrain_motion_and_publish_cell_layer_c0d841
resolve_actor_terrain_motion_and_publish_cell_layer_c0d836:
    .a16
    eor #$FFFF
    sec
    adc $14
    bpl resolve_actor_terrain_motion_and_publish_cell_layer_c0d841
    clc
    adc $C2
resolve_actor_terrain_motion_and_publish_cell_layer_c0d841:
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $08
    sta $08
    tay
    lda [$0A],Y
    .a16
    and #$00FF
    sta $06
    asl
    asl
    tay
    lda [$0D],Y
    sta $00
    iny
    iny
    lda [$0D],Y
    sta $04
    sep #$20
    lda $00
    .a8
    and #$08
    beq resolve_actor_terrain_motion_and_publish_cell_layer_c0d876
    and $1B
    bne resolve_actor_terrain_motion_and_publish_cell_layer_c0d88e
    lda $1B
    .a8
    eor #$88
    .a8
    and #$F8
    sta $1B
    bra resolve_actor_terrain_motion_and_publish_cell_layer_c0d88e
resolve_actor_terrain_motion_and_publish_cell_layer_c0d876:
    lda $00
    .a8
    and #$07
    .a8
    cmp #$03
    bcc resolve_actor_terrain_motion_and_publish_cell_layer_c0d884
    lda $1B
    .a8
    and #$F7
    bra resolve_actor_terrain_motion_and_publish_cell_layer_c0d88c
resolve_actor_terrain_motion_and_publish_cell_layer_c0d884:
    sta $00
    lda $1B
    .a8
    and #$F0
    ora $00
resolve_actor_terrain_motion_and_publish_cell_layer_c0d88c:
    sta $1B
resolve_actor_terrain_motion_and_publish_cell_layer_c0d88e:
    clc
    rts
