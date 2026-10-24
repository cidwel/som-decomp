; Sprite piece sizes selected bybit5 ofthe frame attribute byte.
.setcpu "65816"
.segment "CODE"
.org $1EE9
boss_animation_sprite_piece_size_values:
    .byte 1 << 4, 1 << 5
