.setcpu "65816"
.segment "CODE"
.org $11CE
map_control_0e11ce:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
