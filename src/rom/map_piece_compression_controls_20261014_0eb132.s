.setcpu "65816"
.segment "CODE"
.org $B132
map_control_0eb132:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
