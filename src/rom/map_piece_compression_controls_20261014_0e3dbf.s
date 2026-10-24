.setcpu "65816"
.segment "CODE"
.org $3DBF
map_control_0e3dbf:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
