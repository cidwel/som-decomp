.setcpu "65816"
.segment "CODE"
.org $2B34
map_control_0d2b34:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
