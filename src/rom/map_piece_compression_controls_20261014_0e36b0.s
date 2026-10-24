.setcpu "65816"
.segment "CODE"
.org $36B0
map_control_0e36b0:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
