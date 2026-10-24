.setcpu "65816"
.segment "CODE"
.org $9DF0
map_control_0e9df0:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
