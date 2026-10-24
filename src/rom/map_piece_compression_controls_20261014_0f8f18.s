.setcpu "65816"
.segment "CODE"
.org $8F18
map_control_0f8f18:
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
