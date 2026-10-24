.setcpu "65816"
.segment "CODE"
.org $4A1F
map_control_0f4a1f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
