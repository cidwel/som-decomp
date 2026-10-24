.setcpu "65816"
.segment "CODE"
.org $E3FA
map_control_0fe3fa:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
