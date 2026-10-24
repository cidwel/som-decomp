.setcpu "65816"
.segment "CODE"
.org $0C00
map_control_0f0c00:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
