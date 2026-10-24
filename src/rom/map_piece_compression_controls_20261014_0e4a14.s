.setcpu "65816"
.segment "CODE"
.org $4A14
map_control_0e4a14:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
