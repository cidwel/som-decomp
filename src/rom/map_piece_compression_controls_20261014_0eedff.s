.setcpu "65816"
.segment "CODE"
.org $EDFF
map_control_0eedff:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
