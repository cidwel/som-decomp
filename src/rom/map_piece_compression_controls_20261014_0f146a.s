.setcpu "65816"
.segment "CODE"
.org $146A
map_control_0f146a:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
