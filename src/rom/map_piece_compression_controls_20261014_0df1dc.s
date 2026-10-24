.setcpu "65816"
.segment "CODE"
.org $F1DC
map_control_0df1dc:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
