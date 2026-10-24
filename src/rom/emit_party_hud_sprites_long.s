; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_party_hud_sprites = $E621

.segment "CODE"
.org $E61D
emit_party_hud_sprites_long:
    jsr emit_party_hud_sprites
    rtl
