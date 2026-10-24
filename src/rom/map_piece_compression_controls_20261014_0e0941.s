.setcpu "65816"
.segment "CODE"
.org $0941
map_control_0e0941:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
