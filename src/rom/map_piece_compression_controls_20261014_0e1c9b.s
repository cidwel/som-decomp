.setcpu "65816"
.segment "CODE"
.org $1C9B
map_control_0e1c9b:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
