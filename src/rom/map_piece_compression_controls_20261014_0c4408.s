.setcpu "65816"
.segment "CODE"
.org $4408
map_control_0c4408:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
