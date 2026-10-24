.setcpu "65816"
.segment "CODE"
.org $668D
map_control_0e668d:
    .byte $C1 ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
