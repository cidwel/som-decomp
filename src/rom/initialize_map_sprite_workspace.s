; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

order_map_sprite_actor_groups = $E8D7

oam_shadow = $0800
oam_high_workspace = $0A00
oam_cursor_low = $7C
oam_cursor_high = $7D
sprite_state_5a = $5A
sprite_state_59 = $59

.segment "CODE"
.org $E355
initialize_map_sprite_workspace:
    rep #$30
    .i16
    ldx #$0000
    .a16
    lda #$E0FF
initialize_map_sprite_workspace_c0e35d:
    sta a:oam_shadow,X
    inx
    inx
    inx
    inx
    .i16
    cpx #$0200
    bcc initialize_map_sprite_workspace_c0e35d
    sep #$30
    .i8
    ldx #$3F
    .a8
    lda #$00
initialize_map_sprite_workspace_c0e36f:
    sta a:oam_high_workspace,X
    dex
    bpl initialize_map_sprite_workspace_c0e36f
    stz oam_cursor_low
    stz oam_cursor_high
    stz sprite_state_5a
    .a8
    lda #$01
    stz sprite_state_59
    jmp order_map_sprite_actor_groups
