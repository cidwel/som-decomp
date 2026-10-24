.setcpu "65816"
.segment "CODE"
.org $B9E4
map_control_0fb9e4:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
