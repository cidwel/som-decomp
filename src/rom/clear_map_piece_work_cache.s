; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CBC2
clear_map_piece_work_cache:
    rep #$20
    sep #$10
    .i8
    ldx #$00
    txa
clear_map_piece_work_cache_c0cbc9:
    sta a:$FF00,X
    inx
    inx
    bne clear_map_piece_work_cache_c0cbc9
    rts
