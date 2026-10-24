.setcpu "65816"
.segment "CODE"
.org $2AF9
map_control_0c2af9:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
