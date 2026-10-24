.setcpu "65816"
.segment "CODE"
.org $5599
map_control_0d5599:
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
