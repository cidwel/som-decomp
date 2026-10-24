.setcpu "65816"
.segment "CODE"
.org $1E4D
map_control_0f1e4d:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
