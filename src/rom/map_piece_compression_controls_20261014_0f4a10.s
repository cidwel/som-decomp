.setcpu "65816"
.segment "CODE"
.org $4A10
map_control_0f4a10:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
