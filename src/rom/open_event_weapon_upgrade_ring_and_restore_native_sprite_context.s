; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-event-handlers.md.
.setcpu "65816"
.smart
.a8
.i16

public_weapon_upgrade_ring_menu_alias = $C0004E
restore_event_menu_sprite_workspace_and_palette = $F3EA
stage_event_menu_sprites_and_preserve_actor_context = $F3F3

.segment "CODE"
.org $EAD6
open_event_weapon_upgrade_ring_and_restore_native_sprite_context:
    rep #$30
    inc $D1
    ldx $3A
    jsr stage_event_menu_sprites_and_preserve_actor_context
    lda $99
    .a16
    and #$00FF
    jsl f:public_weapon_upgrade_ring_menu_alias
    brl restore_event_menu_sprite_workspace_and_palette
