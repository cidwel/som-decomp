.setcpu "65816"
.segment "CODE"
.org $0A41
map_control_0f0a41:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
