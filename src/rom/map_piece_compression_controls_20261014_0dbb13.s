.setcpu "65816"
.segment "CODE"
.org $BB13
map_control_0dbb13:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
