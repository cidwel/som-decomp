.setcpu "65816"
.segment "CODE"
.org $3DD8
map_control_0d3dd8:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
