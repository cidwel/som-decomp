.setcpu "65816"
.segment "CODE"
.org $E3C0
map_control_0de3c0:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
