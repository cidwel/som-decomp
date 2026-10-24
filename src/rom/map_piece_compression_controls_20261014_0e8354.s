.setcpu "65816"
.segment "CODE"
.org $8354
map_control_0e8354:
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
