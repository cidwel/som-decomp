.setcpu "65816"
.segment "CODE"
.org $423D
map_control_0c423d:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
