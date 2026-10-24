.setcpu "65816"
.segment "CODE"
.org $BC81
map_control_0ebc81:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $D4 ; same-value copy count/distance
