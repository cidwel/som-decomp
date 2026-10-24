.setcpu "65816"
.segment "CODE"
.org $78B2
map_control_0f78b2:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
