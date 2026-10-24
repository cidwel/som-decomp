.setcpu "65816"
.segment "CODE"
.org $F1C6
map_control_0df1c6:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
