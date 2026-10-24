.setcpu "65816"
.segment "CODE"
.org $9BFD
map_control_0e9bfd:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count
