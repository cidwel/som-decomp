.setcpu "65816"
.segment "CODE"
.org $4795
map_control_0e4795:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
