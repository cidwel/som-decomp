.setcpu "65816"
.segment "CODE"
.org $F9F2

scene_vram_fixed_attribute_fill_records:
    ; Each record: repeated VRAM high byte, word destination, byte count.
    .byte $0C
    .word $5800, $01C0
    .byte $08
    .word $58E0, $0100
    .byte $04
    .word $5960, $0180
    .byte $0C
    .word $5C00, $01C0
    .byte $08
    .word $5CE0, $0100
    .byte $04
    .word $5D60, $0180
