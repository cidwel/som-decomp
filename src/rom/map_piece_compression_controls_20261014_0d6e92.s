.setcpu "65816"
.segment "CODE"
.org $6E92
map_control_0d6e92:
    .byte $CF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
