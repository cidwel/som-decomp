.setcpu "65816"
.segment "CODE"
.org $4B94
map_control_0f4b94:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
