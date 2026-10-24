; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16

routine_02ab42 = $2AB42

.segment "CODE"
.org $CB88
update_event_sprite_shadow_palette_and_oam_priority:
    jsl f:routine_02ab42
    rep #$30
    .i16
    ldy #$0100
    lda $98
    asl
    asl
    asl
    asl
    sta $00
update_event_sprite_shadow_palette_and_oam_priority_c1cb99:
    lda a:$0802,Y
    .a16
    and #$0E00
    bit $00
    bpl update_event_sprite_shadow_palette_and_oam_priority_c1cbb3
    .a16
    cmp #$0800
    bcs update_event_sprite_shadow_palette_and_oam_priority_c1cbc1
    lda a:$0802,Y
    .a16
    and #$F1FF
    .a16
    ora #$0800
    bra update_event_sprite_shadow_palette_and_oam_priority_c1cbbe
update_event_sprite_shadow_palette_and_oam_priority_c1cbb3:
    .a16
    cmp #$0800
    bcc update_event_sprite_shadow_palette_and_oam_priority_c1cbc1
    lda a:$0802,Y
    .a16
    and #$F1FF
update_event_sprite_shadow_palette_and_oam_priority_c1cbbe:
    sta a:$0802,Y
update_event_sprite_shadow_palette_and_oam_priority_c1cbc1:
    iny
    iny
    iny
    iny
    .i16
    cpy #$0200
    bcc update_event_sprite_shadow_palette_and_oam_priority_c1cb99
    rts
