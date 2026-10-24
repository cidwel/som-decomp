.setcpu "65816"
.segment "CODE"
.org $78E7
map_control_0e78e7:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
