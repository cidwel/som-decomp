.setcpu "65816"
.segment "CODE"
.org $7E06
map_control_0d7e06:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
