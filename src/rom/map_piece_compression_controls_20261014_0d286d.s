.setcpu "65816"
.segment "CODE"
.org $286D
map_control_0d286d:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
