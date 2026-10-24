.setcpu "65816"
.segment "CODE"
.org $9232
map_control_0e9232:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
