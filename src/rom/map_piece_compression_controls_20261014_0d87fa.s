.setcpu "65816"
.segment "CODE"
.org $87FA
map_control_0d87fa:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
