.setcpu "65816"
.segment "CODE"
.org $5BF7
map_control_0d5bf7:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $CB ; same-value copy count/distance
