.setcpu "65816"
.segment "CODE"
.org $10C1
map_control_0e10c1:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
