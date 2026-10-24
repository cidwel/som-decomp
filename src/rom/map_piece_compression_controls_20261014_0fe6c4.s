.setcpu "65816"
.segment "CODE"
.org $E6C4
map_control_0fe6c4:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
