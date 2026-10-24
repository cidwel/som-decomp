.setcpu "65816"
.segment "CODE"
.org $754C
map_control_0d754c:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $4D ; distance low bit/count
