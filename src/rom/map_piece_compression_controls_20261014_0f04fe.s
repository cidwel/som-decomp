.setcpu "65816"
.segment "CODE"
.org $04FE
map_control_0f04fe:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
