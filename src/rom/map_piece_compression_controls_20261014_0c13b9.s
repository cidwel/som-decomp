.setcpu "65816"
.segment "CODE"
.org $13B9
map_control_0c13b9:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
