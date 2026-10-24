.setcpu "65816"
.segment "CODE"
.org $81AE
map_control_0d81ae:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
