.setcpu "65816"
.segment "CODE"
.org $9B0B
map_control_0d9b0b:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
