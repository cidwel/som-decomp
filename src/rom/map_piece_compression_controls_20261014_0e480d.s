.setcpu "65816"
.segment "CODE"
.org $480D
map_control_0e480d:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $9C ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
