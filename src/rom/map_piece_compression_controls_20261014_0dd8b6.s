.setcpu "65816"
.segment "CODE"
.org $D8B6
map_control_0dd8b6:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
