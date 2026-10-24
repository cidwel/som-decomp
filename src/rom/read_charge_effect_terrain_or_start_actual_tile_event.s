; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16

read_charge_effect_terrain_height = $C1D7
routine_01e76d = $1E76D

.segment "CODE"
.org $C183
read_charge_effect_terrain_or_start_actual_tile_event:
    sep #$20
    lda a:$E02C,X
    phx
    php
    jsr read_charge_effect_terrain_height
    xba
    plp
    beq read_charge_effect_terrain_or_start_actual_tile_event_c2c19f
    lda $D0
    bne read_charge_effect_terrain_or_start_actual_tile_event_c2c19f
    lda f:$7F0002,X
    .a8
    and #$F0
    .a8
    cmp #$F0
    beq read_charge_effect_terrain_or_start_actual_tile_event_c2c1ab
read_charge_effect_terrain_or_start_actual_tile_event_c2c19f:
    plx
    lda a:$D000,Y
    .a8
    cmp #$03
    xba
    bcc read_charge_effect_terrain_or_start_actual_tile_event_c2c1aa
    .a8
    lda #$00
read_charge_effect_terrain_or_start_actual_tile_event_c2c1aa:
    rts
read_charge_effect_terrain_or_start_actual_tile_event_c2c1ab:
    lda f:$7F0003,X
    xba
    lda f:$7F0002,X
    asl
    asl
    asl
    asl
    rep #$20
    lsr
    lsr
    lsr
    lsr
    plx
    stx $D4
    phy
    jsl f:routine_01e76d
    ply
    sep #$20
    .a8
    lda #$00
    sta a:$D000,Y
    .a8
    lda #$FF
    rts
