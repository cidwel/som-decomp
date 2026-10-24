.setcpu "65816"
.segment "CODE"
.org $16D1
map_control_0f16d1:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
