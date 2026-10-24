.setcpu "65816"
.segment "CODE"
.org $FA80
map_control_0dfa80:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
