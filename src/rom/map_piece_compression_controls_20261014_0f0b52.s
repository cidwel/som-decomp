.setcpu "65816"
.segment "CODE"
.org $0B52
map_control_0f0b52:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
