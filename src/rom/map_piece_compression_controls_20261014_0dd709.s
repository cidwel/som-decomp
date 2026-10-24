.setcpu "65816"
.segment "CODE"
.org $D709
map_control_0dd709:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
