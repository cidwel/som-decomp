; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_sprite_visibility_timer = $E382
emit_three_actor_auxiliary_sprite_records = $2C3C1
select_and_emit_actor_sprite_lists = $E4C1

.segment "CODE"
.org $E40E
update_actor_screen_position_and_emit_sprites:
    sep #$20
    lda a:$E00B,X
    bpl update_actor_screen_position_and_emit_sprites_c0e443
    rep #$20
    lda a:$E002,X
    sec
    sbc $AC
    sta a:$E020,X
    bcs update_actor_screen_position_and_emit_sprites_c0e42c
    adc $C0
    .a16
    cmp #$0180
    bcs update_actor_screen_position_and_emit_sprites_c0e42c
    sta a:$E020,X
update_actor_screen_position_and_emit_sprites_c0e42c:
    lda a:$E004,X
    sec
    sbc $AE
    sta a:$E022,X
    bcs update_actor_screen_position_and_emit_sprites_c0e46f
    adc $C2
    .a16
    cmp #$0140
    bcs update_actor_screen_position_and_emit_sprites_c0e46f
    sta a:$E022,X
    bra update_actor_screen_position_and_emit_sprites_c0e46f
update_actor_screen_position_and_emit_sprites_c0e443:
    rep #$20
    lda a:$E002,X
    sec
    sbc $A8
    sta a:$E020,X
    bcs update_actor_screen_position_and_emit_sprites_c0e45a
    adc $C0
    .a16
    cmp #$0180
    bcs update_actor_screen_position_and_emit_sprites_c0e45a
    sta a:$E020,X
update_actor_screen_position_and_emit_sprites_c0e45a:
    lda a:$E004,X
    sec
    sbc $AA
    sta a:$E022,X
    bcs update_actor_screen_position_and_emit_sprites_c0e46f
    adc $C2
    .a16
    cmp #$0140
    bcs update_actor_screen_position_and_emit_sprites_c0e46f
    sta a:$E022,X
update_actor_screen_position_and_emit_sprites_c0e46f:
    sep #$20
    lda a:$E00F,X
    beq update_actor_screen_position_and_emit_sprites_c0e47c
    jsr advance_actor_sprite_visibility_timer
    bcc update_actor_screen_position_and_emit_sprites_c0e47c
update_actor_screen_position_and_emit_sprites_c0e47b:
    rts
update_actor_screen_position_and_emit_sprites_c0e47c:
    lda a:$E00E,X
    beq update_actor_screen_position_and_emit_sprites_c0e4b2
    asl
    bcs update_actor_screen_position_and_emit_sprites_c0e47b
    .a8
    and #$06
    beq update_actor_screen_position_and_emit_sprites_c0e4b2
    dec a:$E039,X
    bne update_actor_screen_position_and_emit_sprites_c0e497
    lda a:$E00E,X
    .a8
    and #$F0
    sta a:$E00E,X
    bra update_actor_screen_position_and_emit_sprites_c0e4b2
update_actor_screen_position_and_emit_sprites_c0e497:
    lda $F4
    lsr
    bcs update_actor_screen_position_and_emit_sprites_c0e4b2
    lda a:$E00E,X
    pha
    .a8
    and #$01
    eor a:$E020,X
    sta a:$E020,X
    pla
    .a8
    and #$02
    lsr
    eor a:$E022,X
    sta a:$E022,X
update_actor_screen_position_and_emit_sprites_c0e4b2:
    sep #$20
    lda a:$E061,X
    beq select_and_emit_actor_sprite_lists
    bit $ED
    bvs select_and_emit_actor_sprite_lists
    jsl f:emit_three_actor_auxiliary_sprite_records
