.setcpu "65816"
.segment "CODE"
.org $D965
map_control_0dd965:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
