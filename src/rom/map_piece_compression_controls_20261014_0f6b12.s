.setcpu "65816"
.segment "CODE"
.org $6B12
map_control_0f6b12:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
