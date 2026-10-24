.setcpu "65816"
.segment "CODE"
.org $76E8
map_control_0d76e8:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
