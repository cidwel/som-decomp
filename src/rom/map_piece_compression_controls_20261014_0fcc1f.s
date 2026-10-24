.setcpu "65816"
.segment "CODE"
.org $CC1F
map_control_0fcc1f:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
