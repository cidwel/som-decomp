.setcpu "65816"
.segment "CODE"
.org $4DE5
map_control_0e4de5:
    .byte $EB ; backreference distance high bits
    .byte $9B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
