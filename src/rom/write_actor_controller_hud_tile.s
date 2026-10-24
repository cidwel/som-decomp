; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BF73
write_actor_controller_hud_tile:
    rep #$20
    sec
    .a16
    sbc #$0021
    sta a:$2116
    sep #$20
    lda f:$7EE02C,X
    bne write_actor_controller_hud_tile_c0bf8a
    lda f:$7EE08C,X
    beq write_actor_controller_hud_tile_c0bf9c
write_actor_controller_hud_tile_c0bf8a:
    lsr
    bcs write_actor_controller_hud_tile_c0bf94
    lsr
    bcs write_actor_controller_hud_tile_c0bf98
    .a8
    lda #$23
    bra write_actor_controller_hud_tile_c0bf9e
write_actor_controller_hud_tile_c0bf94:
    .a8
    lda #$21
    bra write_actor_controller_hud_tile_c0bf9e
write_actor_controller_hud_tile_c0bf98:
    .a8
    lda #$22
    bra write_actor_controller_hud_tile_c0bf9e
write_actor_controller_hud_tile_c0bf9c:
    .a8
    lda #$16
write_actor_controller_hud_tile_c0bf9e:
    sta a:$2118
    rts
