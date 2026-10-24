.setcpu "65816"
.segment "CODE"
.org $29D0
map_control_0e29d0:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $CB ; same-value copy count/distance
