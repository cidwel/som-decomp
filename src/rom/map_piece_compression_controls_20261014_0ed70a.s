.setcpu "65816"
.segment "CODE"
.org $D70A
map_control_0ed70a:
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
