.setcpu "65816"
.segment "CODE"
.org $57AF
map_control_0d57af:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
