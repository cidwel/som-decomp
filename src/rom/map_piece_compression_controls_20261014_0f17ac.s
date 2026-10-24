.setcpu "65816"
.segment "CODE"
.org $17AC
map_control_0f17ac:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
