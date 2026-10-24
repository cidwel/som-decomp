.setcpu "65816"
.segment "CODE"
.org $5102
map_control_0c5102:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
