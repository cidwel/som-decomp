.setcpu "65816"
.segment "CODE"
.org $F4D7
map_control_0df4d7:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
