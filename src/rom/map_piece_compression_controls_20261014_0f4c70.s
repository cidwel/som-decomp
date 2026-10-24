.setcpu "65816"
.segment "CODE"
.org $4C70
map_control_0f4c70:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
