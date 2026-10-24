.setcpu "65816"
.segment "CODE"
.org $2214
map_control_0e2214:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
