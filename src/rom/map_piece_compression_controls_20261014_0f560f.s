.setcpu "65816"
.segment "CODE"
.org $560F
map_control_0f560f:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
