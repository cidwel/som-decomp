.setcpu "65816"
.segment "CODE"
.org $E13D
map_control_0de13d:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
