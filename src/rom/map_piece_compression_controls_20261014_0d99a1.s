.setcpu "65816"
.segment "CODE"
.org $99A1
map_control_0d99a1:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
