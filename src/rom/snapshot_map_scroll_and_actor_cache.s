; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_snapshot_actor_position = $CCBA

.segment "CODE"
.org $CBEA
snapshot_map_scroll_and_actor_cache:
    sep #$20
    rep #$10
    phb
    .a8
    lda #$7E
    pha
    plb
    ldx $D4
    rep #$20
    lda a:$E020,X
    sec
    .a16
    sbc #$0080
    sta $00
    sta $04
    lda a:$E022,X
    sec
    .a16
    sbc #$0070
    sta $02
    sta $06
    lda a:$0A80
    .a16
    and #$000F
    bne snapshot_map_scroll_and_actor_cache_c1cc17
    stz $00
snapshot_map_scroll_and_actor_cache_c1cc17:
    lda a:$0A90
    .a16
    and #$000F
    bne snapshot_map_scroll_and_actor_cache_c1cc21
    stz $02
snapshot_map_scroll_and_actor_cache_c1cc21:
    lda a:$0AA0
    .a16
    and #$000F
    bne snapshot_map_scroll_and_actor_cache_c1cc2b
    stz $04
snapshot_map_scroll_and_actor_cache_c1cc2b:
    lda a:$0AB0
    .a16
    and #$000F
    bne snapshot_map_scroll_and_actor_cache_c1cc35
    stz $06
snapshot_map_scroll_and_actor_cache_c1cc35:
    lda $A8
    clc
    adc $00
    bpl snapshot_map_scroll_and_actor_cache_c1cc3f
    clc
    adc $C0
snapshot_map_scroll_and_actor_cache_c1cc3f:
    cmp $C0
    bcc snapshot_map_scroll_and_actor_cache_c1cc45
    sbc $C0
snapshot_map_scroll_and_actor_cache_c1cc45:
    sta a:$CD00
    lda $AA
    clc
    adc $02
    bpl snapshot_map_scroll_and_actor_cache_c1cc52
    clc
    adc $C2
snapshot_map_scroll_and_actor_cache_c1cc52:
    cmp $C2
    bcc snapshot_map_scroll_and_actor_cache_c1cc58
    sbc $C2
snapshot_map_scroll_and_actor_cache_c1cc58:
    sta a:$CD02
    lda $AC
    clc
    adc $04
    bpl snapshot_map_scroll_and_actor_cache_c1cc65
    clc
    adc $C4
snapshot_map_scroll_and_actor_cache_c1cc65:
    cmp $C4
    bcc snapshot_map_scroll_and_actor_cache_c1cc6b
    sbc $C4
snapshot_map_scroll_and_actor_cache_c1cc6b:
    sta a:$CD04
    lda $AE
    clc
    adc $06
    bpl snapshot_map_scroll_and_actor_cache_c1cc78
    clc
    adc $C6
snapshot_map_scroll_and_actor_cache_c1cc78:
    cmp $C6
    bcc snapshot_map_scroll_and_actor_cache_c1cc7e
    sbc $C6
snapshot_map_scroll_and_actor_cache_c1cc7e:
    sta a:$CD06
    lda $DC
    sta a:$CD08
    sep #$20
    lda a:$E00B,X
    sta a:$CD0A
    .i16
    ldx #$0000
    txy
snapshot_map_scroll_and_actor_cache_c1cc92:
    sep #$20
    lda a:$C800,X
    bpl snapshot_map_scroll_and_actor_cache_c1cc9c
    jsr refresh_snapshot_actor_position
snapshot_map_scroll_and_actor_cache_c1cc9c:
    lda a:$C80C,X
    sta a:$CD72,Y
    rep #$20
    lda a:$C80A,X
    sta a:$CD70,Y
    txa
    clc
    .a16
    adc #$0010
    tax
    iny
    iny
    iny
    .i16
    cpy #$0090
    bcc snapshot_map_scroll_and_actor_cache_c1cc92
    plb
    rts
