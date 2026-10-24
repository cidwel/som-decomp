; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


first_group_byte_count = $053E
second_group_byte_count = $057E
actor_active_bytes = $E000
actor_group_flags = $E00B
actor_screen_depths = $E022
scene_flags = $ED
object_scan_flags = $5C

.segment "CODE"
.org $E8D7
order_map_sprite_actor_groups:
    rep #$10
    sep #$20
    phb
    phd
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldy #$0000
    sty a:first_group_byte_count
    sty a:second_group_byte_count
    .i16
    ldy #$1600
    bit scene_flags
    bpl order_map_sprite_actor_groups_c0e8f8
    bit object_scan_flags
    bmi order_map_sprite_actor_groups_c0e8f8
    .i16
    ldy #$0A00
order_map_sprite_actor_groups_c0e8f8:
    sep #$20
    lda a:actor_active_bytes,Y
    bne order_map_sprite_actor_groups_c0e903
    rep #$20
    beq order_map_sprite_actor_groups_c0e92b
order_map_sprite_actor_groups_c0e903:
    lda a:actor_group_flags,Y
    lsr
    rep #$20
    .a16
    lda #$0500
    bcc order_map_sprite_actor_groups_c0e911
    .a16
    lda #$0540
order_map_sprite_actor_groups_c0e911:
    tcd
    lda a:actor_screen_depths,Y
    ldx $3E
    beq order_map_sprite_actor_groups_c0e923
order_map_sprite_actor_groups_c0e919:
    cmp $1E,X
    bcs order_map_sprite_actor_groups_c0e936
    dex
    dex
    bne order_map_sprite_actor_groups_c0e919
    beq order_map_sprite_actor_groups_c0e936
order_map_sprite_actor_groups_c0e923:
    sta $20,X
    sty $00,X
order_map_sprite_actor_groups_c0e927:
    inc $3E
    inc $3E
order_map_sprite_actor_groups_c0e92b:
    tya
    sec
    .a16
    sbc #$0200
    tay
    bpl order_map_sprite_actor_groups_c0e8f8
    pld
    plb
    rts
order_map_sprite_actor_groups_c0e936:
    cpx $3E
    beq order_map_sprite_actor_groups_c0e923
    stx $1E
    pha
    lda $3E
    sec
    sbc $1E
    lsr
    dec
    beq order_map_sprite_actor_groups_c0e958
    .a16
    cmp #$0008
    bcs order_map_sprite_actor_groups_c0e96a
    .a16
    cmp #$0004
    bcs order_map_sprite_actor_groups_c0e95f
    .a16
    cmp #$0002
    bcs order_map_sprite_actor_groups_c0e95b
    brl order_map_sprite_actor_groups_c0e9dc
order_map_sprite_actor_groups_c0e958:
    brl order_map_sprite_actor_groups_c0e9e4
order_map_sprite_actor_groups_c0e95b:
    beq order_map_sprite_actor_groups_c0e9d4
    bra order_map_sprite_actor_groups_c0e9cc
order_map_sprite_actor_groups_c0e95f:
    beq order_map_sprite_actor_groups_c0e9c4
    .a16
    cmp #$0006
    bcc order_map_sprite_actor_groups_c0e9bc
    beq order_map_sprite_actor_groups_c0e9b4
    bra order_map_sprite_actor_groups_c0e9ac
order_map_sprite_actor_groups_c0e96a:
    beq order_map_sprite_actor_groups_c0e9a4
    .a16
    cmp #$000C
    bcs order_map_sprite_actor_groups_c0e97a
    .a16
    cmp #$000A
    bcc order_map_sprite_actor_groups_c0e99c
    beq order_map_sprite_actor_groups_c0e994
    bra order_map_sprite_actor_groups_c0e98c
order_map_sprite_actor_groups_c0e97a:
    beq order_map_sprite_actor_groups_c0e984
    lda $1A,X
    sta $1C,X
    lda $3A,X
    sta $3C,X
order_map_sprite_actor_groups_c0e984:
    lda $18,X
    sta $1A,X
    lda $38,X
    sta $3A,X
order_map_sprite_actor_groups_c0e98c:
    lda $16,X
    sta $18,X
    lda $36,X
    sta $38,X
order_map_sprite_actor_groups_c0e994:
    lda $14,X
    sta $16,X
    lda $34,X
    sta $36,X
order_map_sprite_actor_groups_c0e99c:
    lda $12,X
    sta $14,X
    lda $32,X
    sta $34,X
order_map_sprite_actor_groups_c0e9a4:
    lda $10,X
    sta $12,X
    lda $30,X
    sta $32,X
order_map_sprite_actor_groups_c0e9ac:
    lda $0E,X
    sta $10,X
    lda $2E,X
    sta $30,X
order_map_sprite_actor_groups_c0e9b4:
    lda $0C,X
    sta $0E,X
    lda $2C,X
    sta $2E,X
order_map_sprite_actor_groups_c0e9bc:
    lda $0A,X
    sta $0C,X
    lda $2A,X
    sta $2C,X
order_map_sprite_actor_groups_c0e9c4:
    lda $08,X
    sta $0A,X
    lda $28,X
    sta $2A,X
order_map_sprite_actor_groups_c0e9cc:
    lda $06,X
    sta $08,X
    lda $26,X
    sta $28,X
order_map_sprite_actor_groups_c0e9d4:
    lda $04,X
    sta $06,X
    lda $24,X
    sta $26,X
order_map_sprite_actor_groups_c0e9dc:
    lda $02,X
    sta $04,X
    lda $22,X
    sta $24,X
order_map_sprite_actor_groups_c0e9e4:
    lda $00,X
    sta $02,X
    lda $20,X
    sta $22,X
    pla
    sta $20,X
    sty $00,X
    brl order_map_sprite_actor_groups_c0e927
