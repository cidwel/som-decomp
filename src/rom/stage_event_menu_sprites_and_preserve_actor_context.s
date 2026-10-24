; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-sprite-context.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00e328 = $E328
update_event_sprite_shadow_palette_and_oam_priority = $CB88

.segment "CODE"
.org $F3F3
stage_event_menu_sprites_and_preserve_actor_context:
    phy
    phx
    jsl f:routine_00e328
    rep #$30
    jsr update_event_sprite_shadow_palette_and_oam_priority
    rep #$30
    plx
    ply
    rts
