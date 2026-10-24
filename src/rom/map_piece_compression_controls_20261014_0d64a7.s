.setcpu "65816"
.segment "CODE"
.org $64A7
map_control_0d64a7:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
