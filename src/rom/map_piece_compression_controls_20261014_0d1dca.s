.setcpu "65816"
.segment "CODE"
.org $1DCA
map_control_0d1dca:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
