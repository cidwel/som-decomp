.setcpu "65816"
.segment "CODE"
.org $B0E2
map_control_0db0e2:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
