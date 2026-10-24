.setcpu "65816"
.segment "CODE"
.org $6FAC
map_control_0d6fac:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
