; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E640
emit_packed_actor_sprite_list:
emit_packed_actor_sprite_list_c0e640:
    sep #$20
    ldy $7C
    .i16
    cpy #$0200
    bcs emit_packed_actor_sprite_list_c0e662
    .a8
    lda #$00
    xba
    lda a:$0001,X
    rep #$20
    bpl emit_packed_actor_sprite_list_c0e656
    .a16
    ora #$FF00
emit_packed_actor_sprite_list_c0e656:
    clc
    adc $06
    bmi emit_packed_actor_sprite_list_c0e663
    .a16
    cmp #$00E0
    bcc emit_packed_actor_sprite_list_c0e668
    bcs emit_packed_actor_sprite_list_c0e6c1
emit_packed_actor_sprite_list_c0e662:
    rts
emit_packed_actor_sprite_list_c0e663:
    .a16
    cmp #$FFF0
    bcc emit_packed_actor_sprite_list_c0e6c1
emit_packed_actor_sprite_list_c0e668:
    sep #$20
    sta a:$0801,Y
    .a8
    lda #$00
    xba
    lda a:$0000,X
    rep #$20
    bpl emit_packed_actor_sprite_list_c0e67a
    .a16
    ora #$FF00
emit_packed_actor_sprite_list_c0e67a:
    clc
    adc $04
    bmi emit_packed_actor_sprite_list_c0e686
    .a16
    cmp #$0100
    bcc emit_packed_actor_sprite_list_c0e68b
    bcs emit_packed_actor_sprite_list_c0e6c1
emit_packed_actor_sprite_list_c0e686:
    .a16
    cmp #$FFF0
    bcc emit_packed_actor_sprite_list_c0e6c1
emit_packed_actor_sprite_list_c0e68b:
    sep #$20
    sta a:$0800,Y
    xba
    beq emit_packed_actor_sprite_list_c0e6a3
    .a8
    lda #$00
    xba
    lda $5A
    tay
    lda a:$0A00,Y
    eor $59
    sta a:$0A00,Y
    ldy $7C
emit_packed_actor_sprite_list_c0e6a3:
    rep #$20
    lda a:$0002,X
    sta a:$0802,Y
    tya
    clc
    .a16
    adc #$0004
    tay
    sty $7C
    sep #$20
    lda $59
    asl
    asl
    bcc emit_packed_actor_sprite_list_c0e6bf
    inc $5A
    .a8
    lda #$01
emit_packed_actor_sprite_list_c0e6bf:
    sta $59
emit_packed_actor_sprite_list_c0e6c1:
    sep #$20
    dec $02
    beq emit_packed_actor_sprite_list_c0e6ce
    inx
    inx
    inx
    inx
    brl emit_packed_actor_sprite_list_c0e640
emit_packed_actor_sprite_list_c0e6ce:
    rts
