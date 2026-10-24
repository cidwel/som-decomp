.setcpu "65816"
.segment "CODE"
.org $6DAC
map_control_0f6dac:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
