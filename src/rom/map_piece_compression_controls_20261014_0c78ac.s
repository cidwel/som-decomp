.setcpu "65816"
.segment "CODE"
.org $78AC
map_control_0c78ac:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
