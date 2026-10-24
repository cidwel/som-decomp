.setcpu "65816"
.segment "CODE"
.org $428D
map_control_0c428d:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
