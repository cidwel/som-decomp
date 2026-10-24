.setcpu "65816"
.segment "CODE"
.org $D15F
map_control_0fd15f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
