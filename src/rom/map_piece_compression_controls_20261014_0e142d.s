.setcpu "65816"
.segment "CODE"
.org $142D
map_control_0e142d:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
