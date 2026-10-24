.setcpu "65816"
.segment "CODE"
.org $1812
map_control_0f1812:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
