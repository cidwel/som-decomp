.setcpu "65816"
.segment "CODE"
.org $378D
map_control_0d378d:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
