.setcpu "65816"
.segment "CODE"
.org $ABCA
map_control_0eabca:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
