.setcpu "65816"
.segment "CODE"
.org $3975
map_control_0c3975:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
