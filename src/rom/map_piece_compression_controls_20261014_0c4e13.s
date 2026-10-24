.setcpu "65816"
.segment "CODE"
.org $4E13
map_control_0c4e13:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
