.setcpu "65816"
.segment "CODE"
.org $4B22
map_control_0d4b22:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
