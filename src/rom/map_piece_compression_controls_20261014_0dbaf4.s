.setcpu "65816"
.segment "CODE"
.org $BAF4
map_control_0dbaf4:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
