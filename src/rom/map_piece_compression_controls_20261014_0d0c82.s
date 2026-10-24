.setcpu "65816"
.segment "CODE"
.org $0C82
map_control_0d0c82:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
