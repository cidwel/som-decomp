.setcpu "65816"
.segment "CODE"
.org $01BA
map_control_0e01ba:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
