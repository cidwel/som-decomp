.setcpu "65816"
.segment "CODE"
.org $7B72
map_control_0e7b72:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
