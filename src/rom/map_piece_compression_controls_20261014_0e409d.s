.setcpu "65816"
.segment "CODE"
.org $409D
map_control_0e409d:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
