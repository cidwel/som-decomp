.setcpu "65816"
.segment "CODE"
.org $BAD6
map_control_0fbad6:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
