.setcpu "65816"
.segment "CODE"
.org $4A9D
map_control_0e4a9d:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
