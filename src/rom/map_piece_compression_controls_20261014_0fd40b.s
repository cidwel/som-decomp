.setcpu "65816"
.segment "CODE"
.org $D40B
map_control_0fd40b:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
