.setcpu "65816"
.segment "CODE"
.org $74EE
map_control_0f74ee:
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
