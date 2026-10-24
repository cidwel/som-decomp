.setcpu "65816"
.segment "CODE"
.org $4D24
map_control_0f4d24:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
