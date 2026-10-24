; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01df22 = $1DF22

.segment "CODE"
.org $DF55
assign_map_object_priority_and_terrain:
    sep #$20
    lda a:$E03C,X
    .a8
    and #$07
    .a8
    cmp #$04
    bcs assign_map_object_priority_and_terrain_c0df71
    .a8
    lda #$20
    lda a:$E08B,X
    .a8
    and #$CF
    .a8
    ora #$20
    sta a:$E08B,X
    jsl f:routine_01df22
    rts
assign_map_object_priority_and_terrain_c0df71:
    .a8
    and #$03
    lsr
    ror
    ror
    lsr
    lsr
    sta $00
    lda a:$E08B,X
    .a8
    and #$CF
    ora $00
    sta a:$E08B,X
    rts
