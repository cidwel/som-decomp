.setcpu "65816"
.segment "CODE"
.org $74E0
map_control_0d74e0:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
