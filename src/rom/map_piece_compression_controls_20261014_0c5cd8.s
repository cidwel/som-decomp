.setcpu "65816"
.segment "CODE"
.org $5CD8
map_control_0c5cd8:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
