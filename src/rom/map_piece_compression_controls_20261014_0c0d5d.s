.setcpu "65816"
.segment "CODE"
.org $0D5D
map_control_0c0d5d:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
