.setcpu "65816"
.segment "CODE"
.org $4B58
map_control_0f4b58:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
