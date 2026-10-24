.setcpu "65816"
.segment "CODE"
.org $753F
map_control_0d753f:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
