; Packed software OAM bit constants: 255 XOR (3 << (2*phase)).
; Used by tools/map_boss_sprites.py; independently assembled and compared.
.setcpu "65816"
.segment "CODE"
.org $21B3
boss_sprite_packed_attribute_clear_masks:
    .byte $FC, $F3, $CF, $3F
