.setcpu "65816"
.segment "CODE"
.org $ACAC
map_control_0dacac:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
