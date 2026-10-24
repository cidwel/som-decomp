.setcpu "65816"
.segment "CODE"
.org $0D1C
map_control_0c0d1c:
    .byte $D4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
