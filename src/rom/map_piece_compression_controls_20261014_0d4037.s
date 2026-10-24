.setcpu "65816"
.segment "CODE"
.org $4037
map_control_0d4037:
    .byte $D2 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
