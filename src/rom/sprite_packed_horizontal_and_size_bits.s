; Packed software OAM bit constants: 1 << (2*phase), followed by 2 << (2*phase).
; Used by tools/map_boss_sprites.py; independently assembled and compared.
.setcpu "65816"
.segment "CODE"
.org $7F2D
sprite_packed_horizontal_and_size_bits:
    .byte $01, $04, $10, $40, $02, $08, $20, $80
