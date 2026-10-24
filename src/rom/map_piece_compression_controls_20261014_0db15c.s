.setcpu "65816"
.segment "CODE"
.org $B15C
map_control_0db15c:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
