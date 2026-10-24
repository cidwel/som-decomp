.setcpu "65816"
.segment "CODE"
.org $9B93
map_control_0e9b93:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
